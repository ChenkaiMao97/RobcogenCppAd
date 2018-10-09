#include <iostream>
#include <fstream>
#include <ctime>

#include <iit/rbd/rbd.h>
#include <iit/rbd/utils.h>
#include <iit/robots/acrobot/jsim.h>

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

static void fillState(Acrobot::JointState& q, SL_Jstate* SLState);
static void SL_init();

/* This main is supposed to be used to test the joint space inertia matrix routines */
int main(int argc, char**argv)
{
    Acrobot::JointState q;

    SL_init();
    std::srand(std::time(NULL)); // initialize random number generator
    fillState(q, currentState);
    SL_ForDynComp(currentState, &basePosition, &baseOrient, ux, endeff, rbdM, rbdCG);
    Acrobot::dyn::jsim(q);

    Acrobot::dyn::JSIM SLM;

    // Copies the matrix of SL into an Eigen matrix, to make it easier to print, compare, etc.
    SLM(Acrobot::JA,Acrobot::JA) = rbdM[jA][jA];
    SLM(Acrobot::JA,Acrobot::JB) = rbdM[jA][jB];
    SLM(Acrobot::JB,Acrobot::JA) = rbdM[jB][jA];
    SLM(Acrobot::JB,Acrobot::JB) = rbdM[jB][jB];

    rbd::Utils::CwiseAlmostZeroOp<Acrobot::dyn::JSIM::Scalar> almostZero(1E-4);

    cout << "SL:" << endl << SLM.unaryExpr(almostZero) << endl;
    cout << "Me:" << endl << Acrobot::dyn::jsim.unaryExpr(almostZero)  << endl;

    //Acrobot::dyn::JSIM::MatrixType diff = SLM - Acrobot::dyn::jsim;
    //cout << "difference:" << endl << diff.unaryExpr(almostZero) << endl;

    return TRUE;
}


void fillState(Acrobot::JointState& q, SL_Jstate* SLState) {
    static const double max = 12.3;
    q(0) = ( ((double)std::rand()) / RAND_MAX) * max;
    SLState[jA].th = q(0);
    q(1) = ( ((double)std::rand()) / RAND_MAX) * max;
    SLState[jB].th = q(1);
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
