#include <iostream>
#include <fstream>
#include <ctime>

#include <iit/robots/acrobot/declarations.h>
#include <iit/robots/acrobot/forward_dynamics.h>

#include <SL.h>
#include <SL_kinematics.h>
#include <SL_dynamics.h>
#include <SL_user.h>

#include "matlab_log.h"

using namespace std;
using namespace [iit];
using namespace [iit]::Acrobot;
using namespace [iit]::Acrobot::dyn;

static void fillState(JointState& q, JointState& qd, JointState& qdd,
        SL_Jstate* state);

/* This main is supposed to be used to test the inverse dynamics routines */
int main(int argc, char**argv) {
    if(argc < 2) {
        cerr << "Please provide the number of tests to perform" << endl;
        return -1;
    }
    int numOfTests = std::atoi(argv[1]);
    double sl[numOfTests];
    double me[numOfTests];
    int iterations[numOfTests];

    double t0, sl_total, me_total;
    me_total = 0;
    sl_total = 0;

    int t=0,i=0,avg=0;

    JointState q, qd, qdd, tau;
    ForwardDynamics fwdyn;


    SL_Jstate currentState[N_ROBOT_DOFS];
    SL_endeff endeffector[N_ROBOT_ENDEFFECTORS];
    SL_Cstate basePosition;
    SL_quat baseOrient;
    SL_uext extForces[N_ROBOT_DOFS];

    init_kinematics();
    if (!init_dynamics()) {
        cerr << "Error in init_dynamics()" << endl;
        exit(-1);
    }

    for (i = 0; i < N_ROBOT_DOFS; i++) {
        currentState[i].th = 0;
        currentState[i].thd = 0;
        currentState[i].thdd = 0;
        currentState[i].u = 0;
        bzero(extForces[i].f, sizeof(extForces[i].f));
        bzero(extForces[i].t, sizeof(extForces[i].t));
    }

    endeffector[ENDEFF].m = 0; // zero mass -> no endeffector
    for (i = 0; i <= N_CART; i++) {
        basePosition.x[i] = 0;
        basePosition.xd[i] = 0;
        basePosition.xdd[i] = 0;

        endeffector[ENDEFF].mcm[i] = 0;
        endeffector[ENDEFF].cf[i] = 0;
        endeffector[ENDEFF].ct[i] = 0;
        endeffector[ENDEFF].x[i] = 0;
        endeffector[ENDEFF].a[i] = 0;
    }
    bzero(baseOrient.q  , sizeof(baseOrient.q));
    bzero(baseOrient.qd , sizeof(baseOrient.qd));
    bzero(baseOrient.qdd, sizeof(baseOrient.qdd));
    bzero(baseOrient.ad , sizeof(baseOrient.ad));
    bzero(baseOrient.add, sizeof(baseOrient.add));
    baseOrient.q[_Q0_] = 1;

    std::srand(std::time(NULL)); // initialize random number generator

//      // Prints numerical results, for comparison
//      fillState(q, qd, tau, currentState);
//      SL_ForDynArt(currentState, &basePosition, &baseOrient, extForces, endeffector);
//      fwdyn.fd(q, qd, tau, qdd);
//      cout << "SL:" << endl
//      
//         << currentState[::jA].thdd << endl
//         << currentState[::jB].thdd << endl;
//      cout << endl << qdd << endl;
//      return 1;

    int numOfIterations = 1;
    int sl_elapsed = 0;
    int me_elapsed = 0;
    static const int avgFactor = 10;
    for(t=0; t<numOfTests; t++) {
        sl_total = 0;
        me_total = 0;
        numOfIterations = numOfIterations * 10;
        iterations[t] = numOfIterations;

        for(i=0; i<numOfIterations; i++) {
            fillState(q, qd, tau, currentState);

            sl_elapsed = 0;
            me_elapsed = 0;

            for(avg=0; avg < avgFactor; avg++) {
                t0 = std::clock();
                SL_ForDynArt(currentState, &basePosition, &baseOrient, extForces, endeffector);
                sl_elapsed += (std::clock() - t0); // add the time elapsed during the above call

                t0 = std::clock();
                fwdyn.fd(q, qd, tau, qdd);
                me_elapsed += (std::clock() - t0);
            }
            // Add to the total time the average
            sl_total += (sl_elapsed / avgFactor);
            me_total += (me_elapsed / avgFactor);

        }
        // The total execution time, in seconds
        sl[t] = sl_total/CLOCKS_PER_SEC;
        me[t] = me_total/CLOCKS_PER_SEC;
    }


        cout << "SL:";
        for(int t=0; t<numOfTests; t++) {
            cout << " " << sl[t];
        }
        cout << endl;

        cout << "Robogen:";
        for(int t=0; t<numOfTests; t++) {
            cout << " " << me[t];
        }
        cout  << endl;

        std::string roboname("Acrobot");
        std::string algo("forward dynamics - articulated body algorithm");
        matlabLog(numOfTests, iterations, sl, roboname, algo, "SL");
        matlabLog(numOfTests, iterations, me, roboname, algo, "RoboGen");

        return 0;
}

void fillState(JointState& q, JointState& qd, JointState& tau, SL_Jstate* state) {
    static const double max = 5;
    q(Acrobot::JA)   = ( ((double)std::rand()) / RAND_MAX) * max;
    qd(Acrobot::JA)  = ( ((double)std::rand()) / RAND_MAX) * max;
    tau(Acrobot::JA) = ( ((double)std::rand()) / RAND_MAX) * max;

    state[::jA].th  =   q(Acrobot::JA);
    state[::jA].thd =  qd(Acrobot::JA);
    state[::jA].u   = tau(Acrobot::JA);

    q(Acrobot::JB)   = ( ((double)std::rand()) / RAND_MAX) * max;
    qd(Acrobot::JB)  = ( ((double)std::rand()) / RAND_MAX) * max;
    tau(Acrobot::JB) = ( ((double)std::rand()) / RAND_MAX) * max;

    state[::jB].th  =   q(Acrobot::JB);
    state[::jB].thd =  qd(Acrobot::JB);
    state[::jB].u   = tau(Acrobot::JB);

}
