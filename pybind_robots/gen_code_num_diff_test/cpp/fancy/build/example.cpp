#include "declarations.h"
#include "transforms.h"







int main(int argc, char *argv[])
{

iit::Fancy::MotionTransforms xm;
iit::Fancy::JointState q;
//q = ... // set the joint status
std::cout << xm.fr_link2_X_fr_link3(q) << std::endl;



/*
// [...]
    iit::Fancy::JointState q, qd, qdd, tau;
// [...]


    MotionTransforms transforms;
    dyn::InertiaProperties inertias;
    dyn::InverseDynamics invdyn(inertias, transforms);

    invdyn.id(tau, q, qd, qdd);
    */

return 1;
}

