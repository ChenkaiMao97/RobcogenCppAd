#include <iit/commons/SL/eigen_conversion.h>
#include <iit/commons/SL/rbd_conversion.h>
#include <iit/commons/SL/joint_status_conversion.h>

#include <iit/robots/fancy/declarations.h>
#include <iit/robots/fancy/transforms.h>
#include <iit/robots/fancy/jacobians.h>
#include <iit/robots/fancy/traits.h>
#include <iit/robots/fancy/inertia_properties.h>

#include <iit/rbd/utils.h>

#include "robcogen_globals.h"

#include <iostream>

// the system headers
#include "SL_system_headers.h"
#include "SL.h"
#include "SL_user.h"
#include "SL_common.h"
#include "mdefs.h"
#include "SL_kinematics.h"
#include "utility_macros.h"

using namespace iit;
using namespace iit::Fancy;


static JointState q;
static dyn::InertiaProperties inertias;

typedef typename commons::SL::SLtoRobogen<Traits> SLtoRGen;

/*!
 * Original documentation:
 *
 *        computes the m*cog, rotation axis, and local coord.sys. orgin for
 *        every link. This information can be used to compute the COG and
 *        COG jacobians, assuming the mass and center of mass parameters are
 *        properly identified.
 *
 * \param[in]     state   : the state containing th, thd, thdd
 * \param[in]     basec   : the position state of the base
 * \param[in]     baseo   : the orientational state of the base
 * \param[in]     endeff  : the endeffector parameters
 * \param[out]    Xmcog   : array of mass*cog vectors
 * \param[out]    Xaxis   : array of rotation axes
 * \param[out]    Xorigin : array of coord.sys. origin vectors
 * \param[out]    Xlink   : array of link position
 * \param[out]    Ahmat   : homogeneous transformation matrices of each link
 *
 *
 * Marco's notes:
 * I am not really sure what is the difference between Xorigin and Xlink
 */
void linkInformation(
        SL_Jstate *state,
        SL_Cstate *basec,
        SL_quat *baseo,
        SL_endeff *eff,
        double **Xmcog, double **Xaxis, double **Xorigin, double **Xlink,
        double ***Ahmat, double ***Ahmatdof)
{
    // Convenient alias of the global variable
    iit::Fancy::HomogeneousTransforms& HT = * iit::Fancy::SL::homogeneousTransforms;
    // Copy the joint status
    SLtoRGen::pos(state, q);
    // Support vector
    Eigen::Matrix<double,4,1> tmp_vec;

    iit::Fancy::HomogeneousTransforms::MatrixType tmpX = iit::Fancy::HomogeneousTransforms::MatrixType::Identity();
    // The transform from link1 to world
    tmpX = tmpX * HT.fr_FancyBase_X_fr_link1(q);
    
    commons::SL::copy(Xaxis  [::JA], iit::rbd::Utils::zAxis(tmpX) );
    commons::SL::copy(Xorigin[::JA], iit::rbd::Utils::positionVector(tmpX) );
    
    commons::SL::copy(Xlink[::LINK1], iit::rbd::Utils::positionVector(tmpX) );
    commons::SL::copy(Ahmat[::LINK1], tmpX);
    
    tmp_vec.block<3,1>(0,0) = inertias.getCOM_link1() * inertias.getMass_link1();
    tmp_vec(3) = inertias.getMass_link1();
    commons::SL::copy(Xmcog[::JA], tmpX * tmp_vec);
    
    // The transform from link2 to world
    tmpX = tmpX * HT.fr_link1_X_fr_link2(q);
    
    commons::SL::copy(Xaxis  [::JB], iit::rbd::Utils::zAxis(tmpX) );
    commons::SL::copy(Xorigin[::JB], iit::rbd::Utils::positionVector(tmpX) );
    
    commons::SL::copy(Xlink[::LINK2], iit::rbd::Utils::positionVector(tmpX) );
    commons::SL::copy(Ahmat[::LINK2], tmpX);
    
    tmp_vec.block<3,1>(0,0) = inertias.getCOM_link2() * inertias.getMass_link2();
    tmp_vec(3) = inertias.getMass_link2();
    commons::SL::copy(Xmcog[::JB], tmpX * tmp_vec);
    
    // The transform from link3 to world
    tmpX = tmpX * HT.fr_link2_X_fr_link3(q);
    
    commons::SL::copy(Xaxis  [::JC], iit::rbd::Utils::zAxis(tmpX) );
    commons::SL::copy(Xorigin[::JC], iit::rbd::Utils::positionVector(tmpX) );
    
    commons::SL::copy(Xlink[::LINK3], iit::rbd::Utils::positionVector(tmpX) );
    commons::SL::copy(Ahmat[::LINK3], tmpX);
    
    tmp_vec.block<3,1>(0,0) = inertias.getCOM_link3() * inertias.getMass_link3();
    tmp_vec(3) = inertias.getMass_link3();
    commons::SL::copy(Xmcog[::JC], tmpX * tmp_vec);
    
    // The transform from link4 to world
    tmpX = tmpX * HT.fr_link3_X_fr_link4(q);
    
    commons::SL::copy(Xaxis  [::JD], iit::rbd::Utils::zAxis(tmpX) );
    commons::SL::copy(Xorigin[::JD], iit::rbd::Utils::positionVector(tmpX) );
    
    commons::SL::copy(Xlink[::LINK4], iit::rbd::Utils::positionVector(tmpX) );
    commons::SL::copy(Ahmat[::LINK4], tmpX);
    
    tmp_vec.block<3,1>(0,0) = inertias.getCOM_link4() * inertias.getMass_link4();
    tmp_vec(3) = inertias.getMass_link4();
    commons::SL::copy(Xmcog[::JD], tmpX * tmp_vec);
    
    // The transform from link5 to world
    tmpX = tmpX * HT.fr_link4_X_fr_link5(q);
    
    commons::SL::copy(Xaxis  [::JE], iit::rbd::Utils::zAxis(tmpX) );
    commons::SL::copy(Xorigin[::JE], iit::rbd::Utils::positionVector(tmpX) );
    
    commons::SL::copy(Xlink[::LINK5], iit::rbd::Utils::positionVector(tmpX) );
    commons::SL::copy(Ahmat[::LINK5], tmpX);
    
    tmp_vec.block<3,1>(0,0) = inertias.getCOM_link5() * inertias.getMass_link5();
    tmp_vec(3) = inertias.getMass_link5();
    commons::SL::copy(Xmcog[::JE], tmpX * tmp_vec);
    
    //TODO  add the code for the endeffector links!!
}
