

//Implementation of default constructor
template <typename TRAIT>
iit::Fancy::dyn::tpl::JSIM<TRAIT>::JSIM(IProperties& inertiaProperties, FTransforms& forceTransforms) :
    linkInertias(inertiaProperties),
    frcTransf( &forceTransforms ),
    link5_Ic(linkInertias.getTensor_link5())
{
    //Initialize the matrix itself
    this->setZero();
}

#define DATA tpl::JSIM<TRAIT>::operator()

template <typename TRAIT>
const typename iit::Fancy::dyn::tpl::JSIM<TRAIT>& iit::Fancy::dyn::tpl::JSIM<TRAIT>::update(const JointState& state) {
    ForceVector F;

    // Precomputes only once the coordinate transforms:
    frcTransf -> fr_link4_X_fr_link5(state);
    frcTransf -> fr_link3_X_fr_link4(state);
    frcTransf -> fr_link2_X_fr_link3(state);
    frcTransf -> fr_link1_X_fr_link2(state);

    // Initializes the composite inertia tensors
    link1_Ic = linkInertias.getTensor_link1();
    link2_Ic = linkInertias.getTensor_link2();
    link3_Ic = linkInertias.getTensor_link3();
    link4_Ic = linkInertias.getTensor_link4();

    // "Bottom-up" loop to update the inertia-composite property of each link, for the current configuration

    // Link link5:
    iit::rbd::transformInertia<Scalar>(link5_Ic, frcTransf -> fr_link4_X_fr_link5, Ic_spare);
    link4_Ic += Ic_spare;

    F = link5_Ic.col(iit::rbd::AZ);
    DATA(JE, JE) = F(iit::rbd::AZ);

    F = frcTransf -> fr_link4_X_fr_link5 * F;
    DATA(JE, JD) = F(iit::rbd::LZ);
    DATA(JD, JE) = DATA(JE, JD);
    F = frcTransf -> fr_link3_X_fr_link4 * F;
    DATA(JE, JC) = F(iit::rbd::AZ);
    DATA(JC, JE) = DATA(JE, JC);
    F = frcTransf -> fr_link2_X_fr_link3 * F;
    DATA(JE, JB) = F(iit::rbd::LZ);
    DATA(JB, JE) = DATA(JE, JB);
    F = frcTransf -> fr_link1_X_fr_link2 * F;
    DATA(JE, JA) = F(iit::rbd::AZ);
    DATA(JA, JE) = DATA(JE, JA);

    // Link link4:
    iit::rbd::transformInertia<Scalar>(link4_Ic, frcTransf -> fr_link3_X_fr_link4, Ic_spare);
    link3_Ic += Ic_spare;

    F = link4_Ic.col(iit::rbd::LZ);
    DATA(JD, JD) = F(iit::rbd::LZ);

    F = frcTransf -> fr_link3_X_fr_link4 * F;
    DATA(JD, JC) = F(iit::rbd::AZ);
    DATA(JC, JD) = DATA(JD, JC);
    F = frcTransf -> fr_link2_X_fr_link3 * F;
    DATA(JD, JB) = F(iit::rbd::LZ);
    DATA(JB, JD) = DATA(JD, JB);
    F = frcTransf -> fr_link1_X_fr_link2 * F;
    DATA(JD, JA) = F(iit::rbd::AZ);
    DATA(JA, JD) = DATA(JD, JA);

    // Link link3:
    iit::rbd::transformInertia<Scalar>(link3_Ic, frcTransf -> fr_link2_X_fr_link3, Ic_spare);
    link2_Ic += Ic_spare;

    F = link3_Ic.col(iit::rbd::AZ);
    DATA(JC, JC) = F(iit::rbd::AZ);

    F = frcTransf -> fr_link2_X_fr_link3 * F;
    DATA(JC, JB) = F(iit::rbd::LZ);
    DATA(JB, JC) = DATA(JC, JB);
    F = frcTransf -> fr_link1_X_fr_link2 * F;
    DATA(JC, JA) = F(iit::rbd::AZ);
    DATA(JA, JC) = DATA(JC, JA);

    // Link link2:
    iit::rbd::transformInertia<Scalar>(link2_Ic, frcTransf -> fr_link1_X_fr_link2, Ic_spare);
    link1_Ic += Ic_spare;

    F = link2_Ic.col(iit::rbd::LZ);
    DATA(JB, JB) = F(iit::rbd::LZ);

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
void iit::Fancy::dyn::tpl::JSIM<TRAIT>::computeL() {
    L = this -> template triangularView<Eigen::Lower>();
    // Joint jE, index 4 :
    L(4, 4) = std::sqrt(L(4, 4));
    L(4, 3) = L(4, 3) / L(4, 4);
    L(4, 2) = L(4, 2) / L(4, 4);
    L(4, 1) = L(4, 1) / L(4, 4);
    L(4, 0) = L(4, 0) / L(4, 4);
    L(3, 3) = L(3, 3) - L(4, 3) * L(4, 3);
    L(3, 2) = L(3, 2) - L(4, 3) * L(4, 2);
    L(3, 1) = L(3, 1) - L(4, 3) * L(4, 1);
    L(3, 0) = L(3, 0) - L(4, 3) * L(4, 0);
    L(2, 2) = L(2, 2) - L(4, 2) * L(4, 2);
    L(2, 1) = L(2, 1) - L(4, 2) * L(4, 1);
    L(2, 0) = L(2, 0) - L(4, 2) * L(4, 0);
    L(1, 1) = L(1, 1) - L(4, 1) * L(4, 1);
    L(1, 0) = L(1, 0) - L(4, 1) * L(4, 0);
    L(0, 0) = L(0, 0) - L(4, 0) * L(4, 0);
    
    // Joint jD, index 3 :
    L(3, 3) = std::sqrt(L(3, 3));
    L(3, 2) = L(3, 2) / L(3, 3);
    L(3, 1) = L(3, 1) / L(3, 3);
    L(3, 0) = L(3, 0) / L(3, 3);
    L(2, 2) = L(2, 2) - L(3, 2) * L(3, 2);
    L(2, 1) = L(2, 1) - L(3, 2) * L(3, 1);
    L(2, 0) = L(2, 0) - L(3, 2) * L(3, 0);
    L(1, 1) = L(1, 1) - L(3, 1) * L(3, 1);
    L(1, 0) = L(1, 0) - L(3, 1) * L(3, 0);
    L(0, 0) = L(0, 0) - L(3, 0) * L(3, 0);
    
    // Joint jC, index 2 :
    L(2, 2) = std::sqrt(L(2, 2));
    L(2, 1) = L(2, 1) / L(2, 2);
    L(2, 0) = L(2, 0) / L(2, 2);
    L(1, 1) = L(1, 1) - L(2, 1) * L(2, 1);
    L(1, 0) = L(1, 0) - L(2, 1) * L(2, 0);
    L(0, 0) = L(0, 0) - L(2, 0) * L(2, 0);
    
    // Joint jB, index 1 :
    L(1, 1) = std::sqrt(L(1, 1));
    L(1, 0) = L(1, 0) / L(1, 1);
    L(0, 0) = L(0, 0) - L(1, 0) * L(1, 0);
    
    // Joint jA, index 0 :
    L(0, 0) = std::sqrt(L(0, 0));
    
}

template <typename TRAIT>
void iit::Fancy::dyn::tpl::JSIM<TRAIT>::computeInverse() {
    computeLInverse();

    inverse(0, 0) =  + (Linv(0, 0) * Linv(0, 0));
    inverse(1, 1) =  + (Linv(1, 0) * Linv(1, 0)) + (Linv(1, 1) * Linv(1, 1));
    inverse(1, 0) =  + (Linv(1, 0) * Linv(0, 0));
    inverse(0, 1) = inverse(1, 0);
    inverse(2, 2) =  + (Linv(2, 0) * Linv(2, 0)) + (Linv(2, 1) * Linv(2, 1)) + (Linv(2, 2) * Linv(2, 2));
    inverse(2, 1) =  + (Linv(2, 0) * Linv(1, 0)) + (Linv(2, 1) * Linv(1, 1));
    inverse(1, 2) = inverse(2, 1);
    inverse(2, 0) =  + (Linv(2, 0) * Linv(0, 0));
    inverse(0, 2) = inverse(2, 0);
    inverse(3, 3) =  + (Linv(3, 0) * Linv(3, 0)) + (Linv(3, 1) * Linv(3, 1)) + (Linv(3, 2) * Linv(3, 2)) + (Linv(3, 3) * Linv(3, 3));
    inverse(3, 2) =  + (Linv(3, 0) * Linv(2, 0)) + (Linv(3, 1) * Linv(2, 1)) + (Linv(3, 2) * Linv(2, 2));
    inverse(2, 3) = inverse(3, 2);
    inverse(3, 1) =  + (Linv(3, 0) * Linv(1, 0)) + (Linv(3, 1) * Linv(1, 1));
    inverse(1, 3) = inverse(3, 1);
    inverse(3, 0) =  + (Linv(3, 0) * Linv(0, 0));
    inverse(0, 3) = inverse(3, 0);
    inverse(4, 4) =  + (Linv(4, 0) * Linv(4, 0)) + (Linv(4, 1) * Linv(4, 1)) + (Linv(4, 2) * Linv(4, 2)) + (Linv(4, 3) * Linv(4, 3)) + (Linv(4, 4) * Linv(4, 4));
    inverse(4, 3) =  + (Linv(4, 0) * Linv(3, 0)) + (Linv(4, 1) * Linv(3, 1)) + (Linv(4, 2) * Linv(3, 2)) + (Linv(4, 3) * Linv(3, 3));
    inverse(3, 4) = inverse(4, 3);
    inverse(4, 2) =  + (Linv(4, 0) * Linv(2, 0)) + (Linv(4, 1) * Linv(2, 1)) + (Linv(4, 2) * Linv(2, 2));
    inverse(2, 4) = inverse(4, 2);
    inverse(4, 1) =  + (Linv(4, 0) * Linv(1, 0)) + (Linv(4, 1) * Linv(1, 1));
    inverse(1, 4) = inverse(4, 1);
    inverse(4, 0) =  + (Linv(4, 0) * Linv(0, 0));
    inverse(0, 4) = inverse(4, 0);
}

template <typename TRAIT>
void iit::Fancy::dyn::tpl::JSIM<TRAIT>::computeLInverse() {
    //assumes L has been computed already
    Linv(0, 0) = 1 / L(0, 0);
    Linv(1, 1) = 1 / L(1, 1);
    Linv(2, 2) = 1 / L(2, 2);
    Linv(3, 3) = 1 / L(3, 3);
    Linv(4, 4) = 1 / L(4, 4);
    Linv(1, 0) = - Linv(0, 0) * ((Linv(1, 1) * L(1, 0)) + 0);
    Linv(2, 1) = - Linv(1, 1) * ((Linv(2, 2) * L(2, 1)) + 0);
    Linv(2, 0) = - Linv(0, 0) * ((Linv(2, 1) * L(1, 0)) + (Linv(2, 2) * L(2, 0)) + 0);
    Linv(3, 2) = - Linv(2, 2) * ((Linv(3, 3) * L(3, 2)) + 0);
    Linv(3, 1) = - Linv(1, 1) * ((Linv(3, 2) * L(2, 1)) + (Linv(3, 3) * L(3, 1)) + 0);
    Linv(3, 0) = - Linv(0, 0) * ((Linv(3, 1) * L(1, 0)) + (Linv(3, 2) * L(2, 0)) + (Linv(3, 3) * L(3, 0)) + 0);
    Linv(4, 3) = - Linv(3, 3) * ((Linv(4, 4) * L(4, 3)) + 0);
    Linv(4, 2) = - Linv(2, 2) * ((Linv(4, 3) * L(3, 2)) + (Linv(4, 4) * L(4, 2)) + 0);
    Linv(4, 1) = - Linv(1, 1) * ((Linv(4, 2) * L(2, 1)) + (Linv(4, 3) * L(3, 1)) + (Linv(4, 4) * L(4, 1)) + 0);
    Linv(4, 0) = - Linv(0, 0) * ((Linv(4, 1) * L(1, 0)) + (Linv(4, 2) * L(2, 0)) + (Linv(4, 3) * L(3, 0)) + (Linv(4, 4) * L(4, 0)) + 0);
}

