#ifndef _IIT_ACROBOT_SL__ROBOGEN_GLOBALS_H_
#define _IIT_ACROBOT_SL__ROBOGEN_GLOBALS_H_

#include <iit/robots/acrobot/declarations.h>
#include <iit/robots/acrobot/kinematics_parameters.h>
#include <iit/robots/acrobot/transforms.h>
#include <iit/robots/acrobot/inertia_properties.h>
#include <iit/robots/acrobot/forward_dynamics.h>
#include <iit/robots/acrobot/inverse_dynamics.h>

#include <SL.h>
#include <SL_user.h>

namespace robot = iit::Acrobot;

namespace iit {
namespace Acrobot {
namespace SL {

extern iit::Acrobot::HomogeneousTransforms* homogeneousTransforms;
extern iit::Acrobot::MotionTransforms* motionTransforms;
extern iit::Acrobot::ForceTransforms* forceTransforms;
extern iit::Acrobot::dyn::InertiaProperties* linksInertia;
extern iit::Acrobot::dyn::ForwardDynamics*   fwdDynEngine;
extern iit::Acrobot::dyn::InverseDynamics*   invDynEngine;


inline void updateEndeffectorsParams(SL_endeff* eff) {
    //TODO
}

void createDefaultTransformsAndDynamics();


}
}
}



#endif
