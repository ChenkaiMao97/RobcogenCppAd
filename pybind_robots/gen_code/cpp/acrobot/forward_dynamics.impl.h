
// Initialization of static-const data
template <typename TRAIT>
const typename iit::Acrobot::dyn::tpl::ForwardDynamics<TRAIT>::ExtForces
    iit::Acrobot::dyn::tpl::ForwardDynamics<TRAIT>::zeroExtForces(Force::Zero());

template <typename TRAIT>
iit::Acrobot::dyn::tpl::ForwardDynamics<TRAIT>::ForwardDynamics(iit::Acrobot::dyn::tpl::InertiaProperties<TRAIT>& inertia, MTransforms& transforms) :
    inertiaProps( & inertia ),
    motionTransforms( & transforms )
{
    link1_v.setZero();
    link1_c.setZero();
    link2_v.setZero();
    link2_c.setZero();

    vcross.setZero();
    Ia_r.setZero();

}

template <typename TRAIT>
void iit::Acrobot::dyn::tpl::ForwardDynamics<TRAIT>::fd(
    JointState& qdd,
    const JointState& qd,
    const JointState& tau,
    const ExtForces& fext/* = zeroExtForces */)
{
    
    link1_AI = inertiaProps->getTensor_link1();
    link1_p = - fext[LINK1];
    link2_AI = inertiaProps->getTensor_link2();
    link2_p = - fext[LINK2];
    // ---------------------- FIRST PASS ---------------------- //
    // Note that, during the first pass, the articulated inertias are really
    //  just the spatial inertia of the links (see assignments above).
    //  Afterwards things change, and articulated inertias shall not be used
    //  in functions which work specifically with spatial inertias.
    
    // + Link link1
    //  - The spatial velocity:
    link1_v(iit::rbd::AZ) = qd(JA);
    
    //  - The bias force term:
    link1_p += iit::rbd::vxIv(qd(JA), link1_AI);
    
    // + Link link2
    //  - The spatial velocity:
    link2_v = (motionTransforms-> fr_link2_X_fr_link1) * link1_v;
    link2_v(iit::rbd::AZ) += qd(JB);
    
    //  - The velocity-product acceleration term:
    iit::rbd::motionCrossProductMx<Scalar>(link2_v, vcross);
    link2_c = vcross.col(iit::rbd::AZ) * qd(JB);
    
    //  - The bias force term:
    link2_p += iit::rbd::vxIv(link2_v, link2_AI);
    
    
    // ---------------------- SECOND PASS ---------------------- //
    Matrix66S IaB;
    Force pa;
    
    // + Link link2
    link2_u = tau(JB) - link2_p(iit::rbd::AZ);
    link2_U = link2_AI.col(iit::rbd::AZ);
    link2_D = link2_U(iit::rbd::AZ);
    
    iit::rbd::compute_Ia_revolute(link2_AI, link2_U, link2_D, Ia_r);  // same as: Ia_r = link2_AI - link2_U/link2_D * link2_U.transpose();
    pa = link2_p + Ia_r * link2_c + link2_U * link2_u/link2_D;
    ctransform_Ia_revolute(Ia_r, motionTransforms-> fr_link2_X_fr_link1, IaB);
    link1_AI += IaB;
    link1_p += (motionTransforms-> fr_link2_X_fr_link1).transpose() * pa;
    
    // + Link link1
    link1_u = tau(JA) - link1_p(iit::rbd::AZ);
    link1_U = link1_AI.col(iit::rbd::AZ);
    link1_D = link1_U(iit::rbd::AZ);
    
    
    
    // ---------------------- THIRD PASS ---------------------- //
    link1_a = (motionTransforms-> fr_link1_X_fr_AcrobotBase).col(iit::rbd::LZ) * Scalar(iit::rbd::g);
    qdd(JA) = (link1_u - link1_U.dot(link1_a)) / link1_D;
    link1_a(iit::rbd::AZ) += qdd(JA);
    
    link2_a = (motionTransforms-> fr_link2_X_fr_link1) * link1_a + link2_c;
    qdd(JB) = (link2_u - link2_U.dot(link2_a)) / link2_D;
    link2_a(iit::rbd::AZ) += qdd(JB);
    
    
}
