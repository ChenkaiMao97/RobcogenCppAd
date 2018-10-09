#include <iit/commons/SL/eigen_conversion.h>
#include <iit/commons/SL/rbd_conversion.h>
#include <iit/commons/SL/joint_status_conversion.h>

#include <iit/robots/acrobot/declarations.h>
#include <iit/robots/acrobot/transforms.h>
#include <iit/robots/acrobot/jacobians.h>
#include <iit/robots/acrobot/traits.h>
#include <iit/robots/acrobot/inertia_properties.h>

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
using namespace iit::Acrobot;


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
    iit::Acrobot::HomogeneousTransforms& HT = * iit::Acrobot::SL::homogeneousTransforms;
    // Copy the joint status
    SLtoRGen::pos(state, q);
    // Support vector
    Eigen::Matrix<double,4,1> tmp_vec;

    iit::Acrobot::HomogeneousTransforms::MatrixType tmpX = iit::Acrobot::HomogeneousTransforms::MatrixType::Identity();
    // The transform from link1 to world
    tmpX = tmpX * HT.fr_AcrobotBase_X_fr_link1(q);
    
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
    
    //TODO  add the code for the endeffector links!!
}
