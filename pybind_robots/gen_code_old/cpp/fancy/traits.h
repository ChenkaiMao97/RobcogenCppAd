#ifndef IIT_ROBOGEN__FANCY_TRAITS_H_
#define IIT_ROBOGEN__FANCY_TRAITS_H_

#include "declarations.h"
#include "transforms.h"
#include "inverse_dynamics.h"
#include "forward_dynamics.h"
#include "jsim.h"
#include "inertia_properties.h"
#include "jacobians.h"
#include <iit/rbd/traits/TraitSelector.h>


namespace iit {
namespace Fancy {

namespace tpl {

template <typename SCALAR>
struct Traits {
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    typedef SCALAR S;

    typedef typename Fancy::JointIdentifiers JointID;
    typedef typename Fancy::LinkIdentifiers  LinkID;
    typedef typename iit::rbd::tpl::TraitSelector<SCALAR>::Trait Trait;

    typedef typename Fancy::tpl::JointState<SCALAR> JointState;



    typedef typename Fancy::tpl::HomogeneousTransforms<Trait> HomogeneousTransforms;
    typedef typename Fancy::tpl::MotionTransforms<Trait> MotionTransforms;
    typedef typename Fancy::tpl::ForceTransforms<Trait> ForceTransforms;
    typedef typename Fancy::tpl::Jacobians<Trait> Jacobians;

    typedef typename iit::Fancy::dyn::tpl::InertiaProperties<Trait> InertiaProperties;
    typedef typename iit::Fancy::dyn::tpl::ForwardDynamics<Trait> FwdDynEngine;
    typedef typename iit::Fancy::dyn::tpl::InverseDynamics<Trait> InvDynEngine;
    typedef typename iit::Fancy::dyn::tpl::JSIM<Trait> JSIM;

    static const int joints_count = Fancy::jointsCount;
    static const int links_count  = Fancy::linksCount;
    static const bool floating_base = false;

    static inline const JointID* orderedJointIDs();
    static inline const LinkID*  orderedLinkIDs();
};

template <typename SCALAR>
inline const typename Traits<SCALAR>::JointID*  Traits<SCALAR>::orderedJointIDs() {
    return Fancy::orderedJointIDs;
}
template <typename SCALAR>
inline const typename Traits<SCALAR>::LinkID*  Traits<SCALAR>::orderedLinkIDs() {
    return Fancy::orderedLinkIDs;
}

}

typedef tpl::Traits<double> Traits; // default instantiation - backward compatibility...

}
}

#endif
