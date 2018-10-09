#ifndef _IIT_FANCY_SL__ROBOGEN_GLOBALS_H_
#define _IIT_FANCY_SL__ROBOGEN_GLOBALS_H_

#include <iit/robots/fancy/declarations.h>
#include <iit/robots/fancy/kinematics_parameters.h>
#include <iit/robots/fancy/transforms.h>
#include <iit/robots/fancy/inertia_properties.h>
#include <iit/robots/fancy/forward_dynamics.h>
#include <iit/robots/fancy/inverse_dynamics.h>

#include <SL.h>
#include <SL_user.h>

namespace robot = iit::Fancy;

namespace iit {
namespace Fancy {
namespace SL {

extern iit::Fancy::HomogeneousTransforms* homogeneousTransforms;
extern iit::Fancy::MotionTransforms* motionTransforms;
extern iit::Fancy::ForceTransforms* forceTransforms;
extern iit::Fancy::dyn::InertiaProperties* linksInertia;
extern iit::Fancy::dyn::ForwardDynamics*   fwdDynEngine;
extern iit::Fancy::dyn::InverseDynamics*   invDynEngine;


inline void updateEndeffectorsParams(SL_endeff* eff) {
    //TODO
}

void createDefaultTransformsAndDynamics();


}
}
}



#endif
