#ifndef ACROBOT_TRANSFORMS_H_
#define ACROBOT_TRANSFORMS_H_

#include <Eigen/Dense>
#include <iit/rbd/TransformsBase.h>
#include "declarations.h"
#include <iit/rbd/traits/DoubleTrait.h>
#include "kinematics_parameters.h"

namespace iit {
namespace Acrobot {

template<typename SCALAR, class M>
class TransformMotion : public iit::rbd::SpatialTransformBase<tpl::JointState<SCALAR>, M> {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

template<typename SCALAR, class M>
class TransformForce : public iit::rbd::SpatialTransformBase<tpl::JointState<SCALAR>, M> {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

template<typename SCALAR, class M>
class TransformHomogeneous : public iit::rbd::HomogeneousTransformBase<tpl::JointState<SCALAR>, M> {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

namespace tpl {


/**
 * The class for the 6-by-6 coordinates transformation matrices for
 * spatial motion vectors.
 */
template <typename TRAIT>
class MotionTransforms {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    typedef typename TRAIT::Scalar Scalar;

    typedef JointState<Scalar> JState;
    class Dummy {};
    typedef typename TransformMotion<Scalar, Dummy>::MatrixType MatrixType;
public:
    class Type_fr_link1_X_fr_AcrobotBase : public TransformMotion<Scalar, Type_fr_link1_X_fr_AcrobotBase>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link1_X_fr_AcrobotBase();
        const Type_fr_link1_X_fr_AcrobotBase& update(const JState&);
    protected:
    };
    
    class Type_fr_AcrobotBase_X_fr_link1 : public TransformMotion<Scalar, Type_fr_AcrobotBase_X_fr_link1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_AcrobotBase_X_fr_link1();
        const Type_fr_AcrobotBase_X_fr_link1& update(const JState&);
    protected:
    };
    
    class Type_fr_link2_X_fr_link1 : public TransformMotion<Scalar, Type_fr_link2_X_fr_link1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link2_X_fr_link1();
        const Type_fr_link2_X_fr_link1& update(const JState&);
    protected:
    };
    
    class Type_fr_link1_X_fr_link2 : public TransformMotion<Scalar, Type_fr_link1_X_fr_link2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link1_X_fr_link2();
        const Type_fr_link1_X_fr_link2& update(const JState&);
    protected:
    };
    
public:
    MotionTransforms();
    void updateParameters();
    Type_fr_link1_X_fr_AcrobotBase fr_link1_X_fr_AcrobotBase;
    Type_fr_AcrobotBase_X_fr_link1 fr_AcrobotBase_X_fr_link1;
    Type_fr_link2_X_fr_link1 fr_link2_X_fr_link1;
    Type_fr_link1_X_fr_link2 fr_link1_X_fr_link2;

protected:

}; //class 'MotionTransforms'

/**
 * The class for the 6-by-6 coordinates transformation matrices for
 * spatial force vectors.
 */
template <typename TRAIT>
class ForceTransforms {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    typedef typename TRAIT::Scalar Scalar;

    typedef JointState<Scalar> JState;
    class Dummy {};
    typedef typename TransformForce<Scalar, Dummy>::MatrixType MatrixType;
public:
    class Type_fr_link1_X_fr_AcrobotBase : public TransformForce<Scalar, Type_fr_link1_X_fr_AcrobotBase>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link1_X_fr_AcrobotBase();
        const Type_fr_link1_X_fr_AcrobotBase& update(const JState&);
    protected:
    };
    
    class Type_fr_AcrobotBase_X_fr_link1 : public TransformForce<Scalar, Type_fr_AcrobotBase_X_fr_link1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_AcrobotBase_X_fr_link1();
        const Type_fr_AcrobotBase_X_fr_link1& update(const JState&);
    protected:
    };
    
    class Type_fr_link2_X_fr_link1 : public TransformForce<Scalar, Type_fr_link2_X_fr_link1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link2_X_fr_link1();
        const Type_fr_link2_X_fr_link1& update(const JState&);
    protected:
    };
    
    class Type_fr_link1_X_fr_link2 : public TransformForce<Scalar, Type_fr_link1_X_fr_link2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link1_X_fr_link2();
        const Type_fr_link1_X_fr_link2& update(const JState&);
    protected:
    };
    
public:
    ForceTransforms();
    void updateParameters();
    Type_fr_link1_X_fr_AcrobotBase fr_link1_X_fr_AcrobotBase;
    Type_fr_AcrobotBase_X_fr_link1 fr_AcrobotBase_X_fr_link1;
    Type_fr_link2_X_fr_link1 fr_link2_X_fr_link1;
    Type_fr_link1_X_fr_link2 fr_link1_X_fr_link2;

protected:

}; //class 'ForceTransforms'

/**
 * The class with the homogeneous (4x4) coordinates transformation
 * matrices.
 */
template <typename TRAIT>
class HomogeneousTransforms {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    typedef typename TRAIT::Scalar Scalar;

    typedef JointState<Scalar> JState;
    class Dummy {};
    typedef typename TransformHomogeneous<Scalar, Dummy>::MatrixType MatrixType;
public:
    class Type_fr_link1_X_fr_AcrobotBase : public TransformHomogeneous<Scalar, Type_fr_link1_X_fr_AcrobotBase>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link1_X_fr_AcrobotBase();
        const Type_fr_link1_X_fr_AcrobotBase& update(const JState&);
    protected:
    };
    
    class Type_fr_AcrobotBase_X_fr_link1 : public TransformHomogeneous<Scalar, Type_fr_AcrobotBase_X_fr_link1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_AcrobotBase_X_fr_link1();
        const Type_fr_AcrobotBase_X_fr_link1& update(const JState&);
    protected:
    };
    
    class Type_fr_link2_X_fr_link1 : public TransformHomogeneous<Scalar, Type_fr_link2_X_fr_link1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link2_X_fr_link1();
        const Type_fr_link2_X_fr_link1& update(const JState&);
    protected:
    };
    
    class Type_fr_link1_X_fr_link2 : public TransformHomogeneous<Scalar, Type_fr_link1_X_fr_link2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link1_X_fr_link2();
        const Type_fr_link1_X_fr_link2& update(const JState&);
    protected:
    };
    
public:
    HomogeneousTransforms();
    void updateParameters();
    Type_fr_link1_X_fr_AcrobotBase fr_link1_X_fr_AcrobotBase;
    Type_fr_AcrobotBase_X_fr_link1 fr_AcrobotBase_X_fr_link1;
    Type_fr_link2_X_fr_link1 fr_link2_X_fr_link1;
    Type_fr_link1_X_fr_link2 fr_link1_X_fr_link2;

protected:

}; //class 'HomogeneousTransforms'

}

using MotionTransforms = tpl::MotionTransforms<rbd::DoubleTrait>;
using ForceTransforms = tpl::ForceTransforms<rbd::DoubleTrait>;
using HomogeneousTransforms = tpl::HomogeneousTransforms<rbd::DoubleTrait>;

}
}

#include "transforms.impl.h"

#endif
