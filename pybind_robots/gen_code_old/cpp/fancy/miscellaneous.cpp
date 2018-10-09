#include <iit/rbd/utils.h>
#include "miscellaneous.h"

using namespace iit::Fancy;
using namespace iit::Fancy::dyn;

iit::rbd::Vector3d iit::Fancy::getWholeBodyCOM(
    const InertiaProperties& inertiaProps,
    const HomogeneousTransforms& ht)
{
    iit::rbd::Vector3d tmpSum(iit::rbd::Vector3d::Zero());


    HomogeneousTransforms::MatrixType tmpX(HomogeneousTransforms::MatrixType::Identity());
    tmpX = tmpX * ht.fr_FancyBase_X_fr_link1;
    tmpSum += inertiaProps.getMass_link1() *
            ( iit::rbd::Utils::transform(tmpX, inertiaProps.getCOM_link1()));
    
    tmpX = tmpX * ht.fr_link1_X_fr_link2;
    tmpSum += inertiaProps.getMass_link2() *
            ( iit::rbd::Utils::transform(tmpX, inertiaProps.getCOM_link2()));
    
    tmpX = tmpX * ht.fr_link2_X_fr_link3;
    tmpSum += inertiaProps.getMass_link3() *
            ( iit::rbd::Utils::transform(tmpX, inertiaProps.getCOM_link3()));
    
    tmpX = tmpX * ht.fr_link3_X_fr_link4;
    tmpSum += inertiaProps.getMass_link4() *
            ( iit::rbd::Utils::transform(tmpX, inertiaProps.getCOM_link4()));
    
    tmpX = tmpX * ht.fr_link4_X_fr_link5;
    tmpSum += inertiaProps.getMass_link5() *
            ( iit::rbd::Utils::transform(tmpX, inertiaProps.getCOM_link5()));
    

    return tmpSum / inertiaProps.getTotalMass();
}

iit::rbd::Vector3d iit::Fancy::getWholeBodyCOM(
    const InertiaProperties& inertiaProps,
    const JointState& q,
    HomogeneousTransforms& ht)
{
    // First updates the coordinate transforms that will be used by the routine
    ht.fr_FancyBase_X_fr_link1(q);
    ht.fr_link1_X_fr_link2(q);
    ht.fr_link2_X_fr_link3(q);
    ht.fr_link3_X_fr_link4(q);
    ht.fr_link4_X_fr_link5(q);

    // The actual calculus
    return getWholeBodyCOM(inertiaProps, ht);
}
