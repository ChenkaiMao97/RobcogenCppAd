

//Implementation of default constructor
template <typename TRAIT>
iit::Acrobot::dyn::tpl::JSIM<TRAIT>::JSIM(IProperties& inertiaProperties, FTransforms& forceTransforms) :
    linkInertias(inertiaProperties),
    frcTransf( &forceTransforms ),
    link2_Ic(linkInertias.getTensor_link2())
{
    //Initialize the matrix itself
    this->setZero();
}

#define DATA tpl::JSIM<TRAIT>::operator()

template <typename TRAIT>
const typename iit::Acrobot::dyn::tpl::JSIM<TRAIT>& iit::Acrobot::dyn::tpl::JSIM<TRAIT>::update(const JointState& state) {
    ForceVector F;

    // Precomputes only once the coordinate transforms:
    frcTransf -> fr_link1_X_fr_link2(state);

    // Initializes the composite inertia tensors
    link1_Ic = linkInertias.getTensor_link1();

    // "Bottom-up" loop to update the inertia-composite property of each link, for the current configuration

    // Link link2:
    iit::rbd::transformInertia<Scalar>(link2_Ic, frcTransf -> fr_link1_X_fr_link2, Ic_spare);
    link1_Ic += Ic_spare;

    F = link2_Ic.col(iit::rbd::AZ);
    DATA(JB, JB) = F(iit::rbd::AZ);

    F = frcTransf -> fr_link1_X_fr_link2 * F;
    DATA(JB, JA) = F(iit::rbd::AZ);
    DATA(JA, JB) = DATA(JB, JA);

    // Link link1:

    F = link1_Ic.col(iit::rbd::AZ);
    DATA(JA, JA) = F(iit::rbd::AZ);


    return *this;
}

#undef DATA
#undef F

template <typename TRAIT>
void iit::Acrobot::dyn::tpl::JSIM<TRAIT>::computeL() {
    L = this -> template triangularView<Eigen::Lower>();
    // Joint jB, index 1 :
    L(1, 1) = std::sqrt(L(1, 1));
    L(1, 0) = L(1, 0) / L(1, 1);
    L(0, 0) = L(0, 0) - L(1, 0) * L(1, 0);
    
    // Joint jA, index 0 :
    L(0, 0) = std::sqrt(L(0, 0));
    
}

template <typename TRAIT>
void iit::Acrobot::dyn::tpl::JSIM<TRAIT>::computeInverse() {
    computeLInverse();

    inverse(0, 0) =  + (Linv(0, 0) * Linv(0, 0));
    inverse(1, 1) =  + (Linv(1, 0) * Linv(1, 0)) + (Linv(1, 1) * Linv(1, 1));
    inverse(1, 0) =  + (Linv(1, 0) * Linv(0, 0));
    inverse(0, 1) = inverse(1, 0);
}

template <typename TRAIT>
void iit::Acrobot::dyn::tpl::JSIM<TRAIT>::computeLInverse() {
    //assumes L has been computed already
    Linv(0, 0) = 1 / L(0, 0);
    Linv(1, 1) = 1 / L(1, 1);
    Linv(1, 0) = - Linv(0, 0) * ((Linv(1, 1) * L(1, 0)) + 0);
}

