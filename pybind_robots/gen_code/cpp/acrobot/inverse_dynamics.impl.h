// Initialization of static-const data
template <typename TRAIT>
const typename iit::Acrobot::dyn::tpl::InverseDynamics<TRAIT>::ExtForces
iit::Acrobot::dyn::tpl::InverseDynamics<TRAIT>::zeroExtForces(Force::Zero());

template <typename TRAIT>
iit::Acrobot::dyn::tpl::InverseDynamics<TRAIT>::InverseDynamics(IProperties& inertia, MTransforms& transforms) :
    inertiaProps( & inertia ),
    xm( & transforms ),
    link1_I(inertiaProps->getTensor_link1() ),
    link2_I(inertiaProps->getTensor_link2() )
    {
#ifndef EIGEN_NO_DEBUG
    std::cout << "Robot Acrobot, InverseDynamics<TRAIT>::InverseDynamics()" << std::endl;
    std::cout << "Compiled with Eigen debug active" << std::endl;
#endif
    link1_v.setZero();
    link2_v.setZero();

    vcross.setZero();
}

template <typename TRAIT>
void iit::Acrobot::dyn::tpl::InverseDynamics<TRAIT>::id(
    JointState& jForces,
    const JointState& qd, const JointState& qdd,
    const ExtForces& fext)
{
    firstPass(qd, qdd, fext);
    secondPass(jForces);
}

template <typename TRAIT>
void iit::Acrobot::dyn::tpl::InverseDynamics<TRAIT>::G_terms(JointState& jForces)
{
    // Link 'link1'
    link1_a = (xm->fr_link1_X_fr_AcrobotBase).col(iit::rbd::LZ) * Scalar(iit::rbd::g);
    link1_f = link1_I * link1_a;
    // Link 'link2'
    link2_a = (xm->fr_link2_X_fr_link1) * link1_a;
    link2_f = link2_I * link2_a;

    secondPass(jForces);
}

template <typename TRAIT>
void iit::Acrobot::dyn::tpl::InverseDynamics<TRAIT>::C_terms(JointState& jForces, const JointState& qd)
{
    // Link 'link1'
    link1_v(iit::rbd::AZ) = qd(JA);   // link1_v = vJ, for the first link of a fixed base robot
    
    link1_f = iit::rbd::vxIv(qd(JA), link1_I);
    
    // Link 'link2'
    link2_v = ((xm->fr_link2_X_fr_link1) * link1_v);
    link2_v(iit::rbd::AZ) += qd(JB);
    
    iit::rbd::motionCrossProductMx<Scalar>(link2_v, vcross);
    
    link2_a = (vcross.col(iit::rbd::AZ) * qd(JB));
    
    link2_f = link2_I * link2_a + iit::rbd::vxIv(link2_v, link2_I);
    

    secondPass(jForces);
}

template <typename TRAIT>
void iit::Acrobot::dyn::tpl::InverseDynamics<TRAIT>::firstPass(const JointState& qd, const JointState& qdd, const ExtForces& fext)
{
    // First pass, link 'link1'
    link1_a = (xm->fr_link1_X_fr_AcrobotBase).col(iit::rbd::LZ) * Scalar(iit::rbd::g);
    link1_a(iit::rbd::AZ) += qdd(JA);
    link1_v(iit::rbd::AZ) = qd(JA);   // link1_v = vJ, for the first link of a fixed base robot
    
    link1_f = link1_I * link1_a + iit::rbd::vxIv(qd(JA), link1_I)  - fext[LINK1];
    
    // First pass, link 'link2'
    link2_v = ((xm->fr_link2_X_fr_link1) * link1_v);
    link2_v(iit::rbd::AZ) += qd(JB);
    
    iit::rbd::motionCrossProductMx<Scalar>(link2_v, vcross);
    
    link2_a = (xm->fr_link2_X_fr_link1) * link1_a + vcross.col(iit::rbd::AZ) * qd(JB);
    link2_a(iit::rbd::AZ) += qdd(JB);
    
    link2_f = link2_I * link2_a + iit::rbd::vxIv(link2_v, link2_I) - fext[LINK2];
    
}

template <typename TRAIT>
void iit::Acrobot::dyn::tpl::InverseDynamics<TRAIT>::secondPass(JointState& jForces)
{
    // Link 'link2'
    jForces(JB) = link2_f(iit::rbd::AZ);
    link1_f += xm->fr_link2_X_fr_link1.transpose() * link2_f;
    // Link 'link1'
    jForces(JA) = link1_f(iit::rbd::AZ);
}
