#ifndef IIT_ROBOGEN__ACROBOT_TRAITS_H_
#define IIT_ROBOGEN__ACROBOT_TRAITS_H_

#include "declarations.h"
#include "transforms.h"
#include "inverse_dynamics.h"
#include "forward_dynamics.h"
#include "jsim.h"
#include "inertia_properties.h"
#include "jacobians.h"
#include <iit/rbd/traits/TraitSelector.h>


namespace iit {
namespace Acrobot {

namespace tpl {

template <typename SCALAR>
struct Traits {
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    typedef SCALAR S;

    typedef typename Acrobot::JointIdentifiers JointID;
    typedef typename Acrobot::LinkIdentifiers  LinkID;
    typedef typename iit::rbd::tpl::TraitSelector<SCALAR>::Trait Trait;

    typedef typename Acrobot::tpl::JointState<SCALAR> JointState;



    typedef typename Acrobot::tpl::HomogeneousTransforms<Trait> HomogeneousTransforms;
    typedef typename Acrobot::tpl::MotionTransforms<Trait> MotionTransforms;
    typedef typename Acrobot::tpl::ForceTransforms<Trait> ForceTransforms;
    typedef typename Acrobot::tpl::Jacobians<Trait> Jacobians;

    typedef typename iit::Acrobot::dyn::tpl::InertiaProperties<Trait> InertiaProperties;
    typedef typename iit::Acrobot::dyn::tpl::ForwardDynamics<Trait> FwdDynEngine;
    typedef typename iit::Acrobot::dyn::tpl::InverseDynamics<Trait> InvDynEngine;
    typedef typename iit::Acrobot::dyn::tpl::JSIM<Trait> JSIM;

    static const int joints_count = Acrobot::jointsCount;
    static const int links_count  = Acrobot::linksCount;
    static const bool floating_base = false;

    static inline const JointID* orderedJointIDs();
    static inline const LinkID*  orderedLinkIDs();
};

template <typename SCALAR>
inline const typename Traits<SCALAR>::JointID*  Traits<SCALAR>::orderedJointIDs() {
    return Acrobot::orderedJointIDs;
}
template <typename SCALAR>
inline const typename Traits<SCALAR>::LinkID*  Traits<SCALAR>::orderedLinkIDs() {
    return Acrobot::orderedLinkIDs;
}

}

typedef tpl::Traits<double> Traits; // default instantiation - backward compatibility...

}
}

#endif
