#include <iostream>
#include <fstream>
#include <ctime>

#include <iit/rbd/rbd.h>
#include <iit/rbd/utils.h>
#include <iit/robots/fancy/jsim.h>

#include "SL.h"
#include "SL_user.h"
#include "SL_kinematics.h"
#include "SL_dynamics.h"

using namespace std;
using namespace [iit];

static SL_Jstate currentState[N_ROBOT_DOFS];
static SL_endeff endeffector[N_ROBOT_ENDEFFECTORS];
static SL_Cstate basePosition;
static SL_quat baseOrient;
static SL_uext   ux[N_DOFS+1];
static Matrix rbdM;
static Vector rbdCG;

static void fillState(Fancy::JointState& q, SL_Jstate* SLState);
static void SL_init();

/* This main is supposed to be used to test the joint space inertia matrix routines */
int main(int argc, char**argv)
{
    Fancy::JointState q;

    SL_init();
    std::srand(std::time(NULL)); // initialize random number generator
    fillState(q, currentState);
    SL_ForDynComp(currentState, &basePosition, &baseOrient, ux, endeff, rbdM, rbdCG);
    Fancy::dyn::jsim(q);

    Fancy::dyn::JSIM SLM;

    // Copies the matrix of SL into an Eigen matrix, to make it easier to print, compare, etc.
    SLM(Fancy::JA,Fancy::JA) = rbdM[jA][jA];
    SLM(Fancy::JA,Fancy::JB) = rbdM[jA][jB];
    SLM(Fancy::JA,Fancy::JC) = rbdM[jA][jC];
    SLM(Fancy::JA,Fancy::JD) = rbdM[jA][jD];
    SLM(Fancy::JA,Fancy::JE) = rbdM[jA][jE];
    SLM(Fancy::JB,Fancy::JA) = rbdM[jB][jA];
    SLM(Fancy::JB,Fancy::JB) = rbdM[jB][jB];
    SLM(Fancy::JB,Fancy::JC) = rbdM[jB][jC];
    SLM(Fancy::JB,Fancy::JD) = rbdM[jB][jD];
    SLM(Fancy::JB,Fancy::JE) = rbdM[jB][jE];
    SLM(Fancy::JC,Fancy::JA) = rbdM[jC][jA];
    SLM(Fancy::JC,Fancy::JB) = rbdM[jC][jB];
    SLM(Fancy::JC,Fancy::JC) = rbdM[jC][jC];
    SLM(Fancy::JC,Fancy::JD) = rbdM[jC][jD];
    SLM(Fancy::JC,Fancy::JE) = rbdM[jC][jE];
    SLM(Fancy::JD,Fancy::JA) = rbdM[jD][jA];
    SLM(Fancy::JD,Fancy::JB) = rbdM[jD][jB];
    SLM(Fancy::JD,Fancy::JC) = rbdM[jD][jC];
    SLM(Fancy::JD,Fancy::JD) = rbdM[jD][jD];
    SLM(Fancy::JD,Fancy::JE) = rbdM[jD][jE];
    SLM(Fancy::JE,Fancy::JA) = rbdM[jE][jA];
    SLM(Fancy::JE,Fancy::JB) = rbdM[jE][jB];
    SLM(Fancy::JE,Fancy::JC) = rbdM[jE][jC];
    SLM(Fancy::JE,Fancy::JD) = rbdM[jE][jD];
    SLM(Fancy::JE,Fancy::JE) = rbdM[jE][jE];

    rbd::Utils::CwiseAlmostZeroOp<Fancy::dyn::JSIM::Scalar> almostZero(1E-4);

    cout << "SL:" << endl << SLM.unaryExpr(almostZero) << endl;
    cout << "Me:" << endl << Fancy::dyn::jsim.unaryExpr(almostZero)  << endl;

    //Fancy::dyn::JSIM::MatrixType diff = SLM - Fancy::dyn::jsim;
    //cout << "difference:" << endl << diff.unaryExpr(almostZero) << endl;

    return TRUE;
}


void fillState(Fancy::JointState& q, SL_Jstate* SLState) {
    static const double max = 12.3;
    q(0) = ( ((double)std::rand()) / RAND_MAX) * max;
    SLState[jA].th = q(0);
    q(1) = ( ((double)std::rand()) / RAND_MAX) * max;
    SLState[jB].th = q(1);
    q(2) = ( ((double)std::rand()) / RAND_MAX) * max;
    SLState[jC].th = q(2);
    q(3) = ( ((double)std::rand()) / RAND_MAX) * max;
    SLState[jD].th = q(3);
    q(4) = ( ((double)std::rand()) / RAND_MAX) * max;
    SLState[jE].th = q(4);
}

static void SL_init() {
    init_kinematics();
    init_dynamics();

    bzero((void *)&basePosition,sizeof(basePosition));
    bzero((void *)&baseOrient,sizeof(baseOrient));
    bzero((void *)ux,sizeof(SL_uext)*N_DOFS+1);
    setDefaultEndeffector(); // the the default end-effector parameters

    baseOrient.q[_Q0_] = 1;
    baseOrient.q[_Q1_] = 0;
    baseOrient.q[_Q2_] = 0;
    baseOrient.q[_Q3_] = 0;

    rbdM = my_matrix(1,N_DOFS+6,1,N_DOFS+6);
    rbdCG = my_vector(1,N_DOFS+6);
    mat_zero(rbdM);
    vec_zero(rbdCG);

    freeze_base = TRUE;//
}
