#ifndef FANCY_TRANSFORMS_H_
#define FANCY_TRANSFORMS_H_

#include <Eigen/Dense>
#include <iit/rbd/TransformsBase.h>
#include "declarations.h"
#include <iit/rbd/traits/DoubleTrait.h>
#include "kinematics_parameters.h"

namespace iit {
namespace Fancy {

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
    class Type_fr_link1_X_fr_FancyBase : public TransformMotion<Scalar, Type_fr_link1_X_fr_FancyBase>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link1_X_fr_FancyBase();
        const Type_fr_link1_X_fr_FancyBase& update(const JState&);
    protected:
    };
    
    class Type_fr_FancyBase_X_fr_link1 : public TransformMotion<Scalar, Type_fr_FancyBase_X_fr_link1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_FancyBase_X_fr_link1();
        const Type_fr_FancyBase_X_fr_link1& update(const JState&);
    protected:
    };
    
    class Type_fr_link2_X_fr_link1 : public TransformMotion<Scalar, Type_fr_link2_X_fr_link1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link2_X_fr_link1(const Params_lengths& _lengths_values);
        const Type_fr_link2_X_fr_link1& update(const JState&);
    protected:
        const Params_lengths* lengths_values;
    };
    
    class Type_fr_link1_X_fr_link2 : public TransformMotion<Scalar, Type_fr_link1_X_fr_link2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link1_X_fr_link2(const Params_lengths& _lengths_values);
        const Type_fr_link1_X_fr_link2& update(const JState&);
    protected:
        const Params_lengths* lengths_values;
    };
    
    class Type_fr_link3_X_fr_link2 : public TransformMotion<Scalar, Type_fr_link3_X_fr_link2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link3_X_fr_link2();
        const Type_fr_link3_X_fr_link2& update(const JState&);
    protected:
    };
    
    class Type_fr_link2_X_fr_link3 : public TransformMotion<Scalar, Type_fr_link2_X_fr_link3>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link2_X_fr_link3();
        const Type_fr_link2_X_fr_link3& update(const JState&);
    protected:
    };
    
    class Type_fr_link4_X_fr_link3 : public TransformMotion<Scalar, Type_fr_link4_X_fr_link3>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link4_X_fr_link3();
        const Type_fr_link4_X_fr_link3& update(const JState&);
    protected:
    };
    
    class Type_fr_link3_X_fr_link4 : public TransformMotion<Scalar, Type_fr_link3_X_fr_link4>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link3_X_fr_link4();
        const Type_fr_link3_X_fr_link4& update(const JState&);
    protected:
    };
    
    class Type_fr_link5_X_fr_link4 : public TransformMotion<Scalar, Type_fr_link5_X_fr_link4>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link5_X_fr_link4();
        const Type_fr_link5_X_fr_link4& update(const JState&);
    protected:
    };
    
    class Type_fr_link4_X_fr_link5 : public TransformMotion<Scalar, Type_fr_link4_X_fr_link5>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link4_X_fr_link5();
        const Type_fr_link4_X_fr_link5& update(const JState&);
    protected:
    };
    
public:
    MotionTransforms(const ParamsGetter_lengths&);
    void updateParameters();
    Type_fr_link1_X_fr_FancyBase fr_link1_X_fr_FancyBase;
    Type_fr_FancyBase_X_fr_link1 fr_FancyBase_X_fr_link1;
    Type_fr_link2_X_fr_link1 fr_link2_X_fr_link1;
    Type_fr_link1_X_fr_link2 fr_link1_X_fr_link2;
    Type_fr_link3_X_fr_link2 fr_link3_X_fr_link2;
    Type_fr_link2_X_fr_link3 fr_link2_X_fr_link3;
    Type_fr_link4_X_fr_link3 fr_link4_X_fr_link3;
    Type_fr_link3_X_fr_link4 fr_link3_X_fr_link4;
    Type_fr_link5_X_fr_link4 fr_link5_X_fr_link4;
    Type_fr_link4_X_fr_link5 fr_link4_X_fr_link5;

protected:
    Params_lengths values_lengths;

    const ParamsGetter_lengths* valuesGetter_lengths;
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
    class Type_fr_link1_X_fr_FancyBase : public TransformForce<Scalar, Type_fr_link1_X_fr_FancyBase>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link1_X_fr_FancyBase();
        const Type_fr_link1_X_fr_FancyBase& update(const JState&);
    protected:
    };
    
    class Type_fr_FancyBase_X_fr_link1 : public TransformForce<Scalar, Type_fr_FancyBase_X_fr_link1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_FancyBase_X_fr_link1();
        const Type_fr_FancyBase_X_fr_link1& update(const JState&);
    protected:
    };
    
    class Type_fr_link2_X_fr_link1 : public TransformForce<Scalar, Type_fr_link2_X_fr_link1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link2_X_fr_link1(const Params_lengths& _lengths_values);
        const Type_fr_link2_X_fr_link1& update(const JState&);
    protected:
        const Params_lengths* lengths_values;
    };
    
    class Type_fr_link1_X_fr_link2 : public TransformForce<Scalar, Type_fr_link1_X_fr_link2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link1_X_fr_link2(const Params_lengths& _lengths_values);
        const Type_fr_link1_X_fr_link2& update(const JState&);
    protected:
        const Params_lengths* lengths_values;
    };
    
    class Type_fr_link3_X_fr_link2 : public TransformForce<Scalar, Type_fr_link3_X_fr_link2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link3_X_fr_link2();
        const Type_fr_link3_X_fr_link2& update(const JState&);
    protected:
    };
    
    class Type_fr_link2_X_fr_link3 : public TransformForce<Scalar, Type_fr_link2_X_fr_link3>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link2_X_fr_link3();
        const Type_fr_link2_X_fr_link3& update(const JState&);
    protected:
    };
    
    class Type_fr_link4_X_fr_link3 : public TransformForce<Scalar, Type_fr_link4_X_fr_link3>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link4_X_fr_link3();
        const Type_fr_link4_X_fr_link3& update(const JState&);
    protected:
    };
    
    class Type_fr_link3_X_fr_link4 : public TransformForce<Scalar, Type_fr_link3_X_fr_link4>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link3_X_fr_link4();
        const Type_fr_link3_X_fr_link4& update(const JState&);
    protected:
    };
    
    class Type_fr_link5_X_fr_link4 : public TransformForce<Scalar, Type_fr_link5_X_fr_link4>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link5_X_fr_link4();
        const Type_fr_link5_X_fr_link4& update(const JState&);
    protected:
    };
    
    class Type_fr_link4_X_fr_link5 : public TransformForce<Scalar, Type_fr_link4_X_fr_link5>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link4_X_fr_link5();
        const Type_fr_link4_X_fr_link5& update(const JState&);
    protected:
    };
    
public:
    ForceTransforms(const ParamsGetter_lengths&);
    void updateParameters();
    Type_fr_link1_X_fr_FancyBase fr_link1_X_fr_FancyBase;
    Type_fr_FancyBase_X_fr_link1 fr_FancyBase_X_fr_link1;
    Type_fr_link2_X_fr_link1 fr_link2_X_fr_link1;
    Type_fr_link1_X_fr_link2 fr_link1_X_fr_link2;
    Type_fr_link3_X_fr_link2 fr_link3_X_fr_link2;
    Type_fr_link2_X_fr_link3 fr_link2_X_fr_link3;
    Type_fr_link4_X_fr_link3 fr_link4_X_fr_link3;
    Type_fr_link3_X_fr_link4 fr_link3_X_fr_link4;
    Type_fr_link5_X_fr_link4 fr_link5_X_fr_link4;
    Type_fr_link4_X_fr_link5 fr_link4_X_fr_link5;

protected:
    Params_lengths values_lengths;

    const ParamsGetter_lengths* valuesGetter_lengths;
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
    class Type_fr_link1_X_fr_FancyBase : public TransformHomogeneous<Scalar, Type_fr_link1_X_fr_FancyBase>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link1_X_fr_FancyBase();
        const Type_fr_link1_X_fr_FancyBase& update(const JState&);
    protected:
    };
    
    class Type_fr_FancyBase_X_fr_link1 : public TransformHomogeneous<Scalar, Type_fr_FancyBase_X_fr_link1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_FancyBase_X_fr_link1();
        const Type_fr_FancyBase_X_fr_link1& update(const JState&);
    protected:
    };
    
    class Type_fr_link2_X_fr_link1 : public TransformHomogeneous<Scalar, Type_fr_link2_X_fr_link1>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link2_X_fr_link1(const Params_lengths& _lengths_values);
        const Type_fr_link2_X_fr_link1& update(const JState&);
    protected:
        const Params_lengths* lengths_values;
    };
    
    class Type_fr_link1_X_fr_link2 : public TransformHomogeneous<Scalar, Type_fr_link1_X_fr_link2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link1_X_fr_link2(const Params_lengths& _lengths_values);
        const Type_fr_link1_X_fr_link2& update(const JState&);
    protected:
        const Params_lengths* lengths_values;
    };
    
    class Type_fr_link3_X_fr_link2 : public TransformHomogeneous<Scalar, Type_fr_link3_X_fr_link2>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link3_X_fr_link2();
        const Type_fr_link3_X_fr_link2& update(const JState&);
    protected:
    };
    
    class Type_fr_link2_X_fr_link3 : public TransformHomogeneous<Scalar, Type_fr_link2_X_fr_link3>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link2_X_fr_link3();
        const Type_fr_link2_X_fr_link3& update(const JState&);
    protected:
    };
    
    class Type_fr_link4_X_fr_link3 : public TransformHomogeneous<Scalar, Type_fr_link4_X_fr_link3>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link4_X_fr_link3();
        const Type_fr_link4_X_fr_link3& update(const JState&);
    protected:
    };
    
    class Type_fr_link3_X_fr_link4 : public TransformHomogeneous<Scalar, Type_fr_link3_X_fr_link4>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link3_X_fr_link4();
        const Type_fr_link3_X_fr_link4& update(const JState&);
    protected:
    };
    
    class Type_fr_link5_X_fr_link4 : public TransformHomogeneous<Scalar, Type_fr_link5_X_fr_link4>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link5_X_fr_link4();
        const Type_fr_link5_X_fr_link4& update(const JState&);
    protected:
    };
    
    class Type_fr_link4_X_fr_link5 : public TransformHomogeneous<Scalar, Type_fr_link4_X_fr_link5>
    {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Type_fr_link4_X_fr_link5();
        const Type_fr_link4_X_fr_link5& update(const JState&);
    protected:
    };
    
public:
    HomogeneousTransforms(const ParamsGetter_lengths&);
    void updateParameters();
    Type_fr_link1_X_fr_FancyBase fr_link1_X_fr_FancyBase;
    Type_fr_FancyBase_X_fr_link1 fr_FancyBase_X_fr_link1;
    Type_fr_link2_X_fr_link1 fr_link2_X_fr_link1;
    Type_fr_link1_X_fr_link2 fr_link1_X_fr_link2;
    Type_fr_link3_X_fr_link2 fr_link3_X_fr_link2;
    Type_fr_link2_X_fr_link3 fr_link2_X_fr_link3;
    Type_fr_link4_X_fr_link3 fr_link4_X_fr_link3;
    Type_fr_link3_X_fr_link4 fr_link3_X_fr_link4;
    Type_fr_link5_X_fr_link4 fr_link5_X_fr_link4;
    Type_fr_link4_X_fr_link5 fr_link4_X_fr_link5;

protected:
    Params_lengths values_lengths;

    const ParamsGetter_lengths* valuesGetter_lengths;
}; //class 'HomogeneousTransforms'

}

using MotionTransforms = tpl::MotionTransforms<rbd::DoubleTrait>;
using ForceTransforms = tpl::ForceTransforms<rbd::DoubleTrait>;
using HomogeneousTransforms = tpl::HomogeneousTransforms<rbd::DoubleTrait>;

}
}

#include "transforms.impl.h"

#endif
