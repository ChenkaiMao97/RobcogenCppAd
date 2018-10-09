#ifndef IIT_ROBOT_ACROBOT_INERTIA_PROPERTIES_H_
#define IIT_ROBOT_ACROBOT_INERTIA_PROPERTIES_H_

#include <iit/rbd/rbd.h>
#include <iit/rbd/InertiaMatrix.h>
#include <iit/rbd/utils.h>
#include <iit/rbd/traits/DoubleTrait.h>

#include "declarations.h"

namespace iit {
namespace Acrobot {
/**
 * This namespace encloses classes and functions related to the Dynamics
 * of the robot Acrobot.
 */
namespace dyn {

using InertiaMatrix = iit::rbd::InertiaMatrixDense;

namespace tpl {

template <typename TRAIT>
class InertiaProperties {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        typedef typename TRAIT::Scalar Scalar;
        // Modified by Kevin:
        // typedef iit::rbd::Core<Scalar> CoreS;
        typedef Eigen::Core<Scalar> CoreS;
        typedef iit::rbd::tpl::InertiaMatrixDense<Scalar> IMatrix; 
        typedef typename CoreS::Vector3 Vec3d;

        InertiaProperties();
        ~InertiaProperties();
        const IMatrix& getTensor_link1() const;
        const IMatrix& getTensor_link2() const;
        Scalar getMass_link1() const;
        Scalar getMass_link2() const;
        const Vec3d& getCOM_link1() const;
        const Vec3d& getCOM_link2() const;
        Scalar getTotalMass() const;

    private:

        IMatrix tensor_link1;
        IMatrix tensor_link2;
        Vec3d com_link1;
        Vec3d com_link2;
};

template <typename TRAIT>
inline InertiaProperties<TRAIT>::~InertiaProperties() {}

template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::IMatrix& InertiaProperties<TRAIT>::getTensor_link1() const {
    return this->tensor_link1;
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::IMatrix& InertiaProperties<TRAIT>::getTensor_link2() const {
    return this->tensor_link2;
}
template <typename TRAIT>
inline typename InertiaProperties<TRAIT>::Scalar InertiaProperties<TRAIT>::getMass_link1() const {
    return this->tensor_link1.getMass();
}
template <typename TRAIT>
inline typename InertiaProperties<TRAIT>::Scalar InertiaProperties<TRAIT>::getMass_link2() const {
    return this->tensor_link2.getMass();
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::Vec3d& InertiaProperties<TRAIT>::getCOM_link1() const {
    return this->com_link1;
}
template <typename TRAIT>
inline const typename InertiaProperties<TRAIT>::Vec3d& InertiaProperties<TRAIT>::getCOM_link2() const {
    return this->com_link2;
}

template <typename TRAIT>
inline typename InertiaProperties<TRAIT>::Scalar InertiaProperties<TRAIT>::getTotalMass() const {
    return 1.0 + 1.0;
}

}

using InertiaProperties = tpl::InertiaProperties<rbd::DoubleTrait>;

}
}
}

#include "inertia_properties.impl.h"

#endif
