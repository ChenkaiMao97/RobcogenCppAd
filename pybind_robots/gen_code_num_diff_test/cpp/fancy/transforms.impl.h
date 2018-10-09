
// Constructors
template <typename TRAIT>
iit::Fancy::tpl::MotionTransforms<TRAIT>::MotionTransforms
    (const ParamsGetter_lengths& getter_lengths)
     :
    fr_link1_X_fr_FancyBase(),
    fr_FancyBase_X_fr_link1(),
    fr_link2_X_fr_link1(values_lengths),
    fr_link1_X_fr_link2(values_lengths),
    fr_link3_X_fr_link2(),
    fr_link2_X_fr_link3(),
    fr_link4_X_fr_link3(),
    fr_link3_X_fr_link4(),
    fr_link5_X_fr_link4(),
    fr_link4_X_fr_link5()
    ,
    valuesGetter_lengths(& getter_lengths)
{
    updateParameters();
}
template <typename TRAIT>
void iit::Fancy::tpl::MotionTransforms<TRAIT>::updateParameters() {
    values_lengths.ee_x = valuesGetter_lengths -> getValue_ee_x();
}

template <typename TRAIT>
iit::Fancy::tpl::ForceTransforms<TRAIT>::ForceTransforms
    (const ParamsGetter_lengths& getter_lengths)
     :
    fr_link1_X_fr_FancyBase(),
    fr_FancyBase_X_fr_link1(),
    fr_link2_X_fr_link1(values_lengths),
    fr_link1_X_fr_link2(values_lengths),
    fr_link3_X_fr_link2(),
    fr_link2_X_fr_link3(),
    fr_link4_X_fr_link3(),
    fr_link3_X_fr_link4(),
    fr_link5_X_fr_link4(),
    fr_link4_X_fr_link5()
    ,
    valuesGetter_lengths(& getter_lengths)
{
    updateParameters();
}
template <typename TRAIT>
void iit::Fancy::tpl::ForceTransforms<TRAIT>::updateParameters() {
    values_lengths.ee_x = valuesGetter_lengths -> getValue_ee_x();
}

template <typename TRAIT>
iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::HomogeneousTransforms
    (const ParamsGetter_lengths& getter_lengths)
     :
    fr_link1_X_fr_FancyBase(),
    fr_FancyBase_X_fr_link1(),
    fr_link2_X_fr_link1(values_lengths),
    fr_link1_X_fr_link2(values_lengths),
    fr_link3_X_fr_link2(),
    fr_link2_X_fr_link3(),
    fr_link4_X_fr_link3(),
    fr_link3_X_fr_link4(),
    fr_link5_X_fr_link4(),
    fr_link4_X_fr_link5()
    ,
    valuesGetter_lengths(& getter_lengths)
{
    updateParameters();
}
template <typename TRAIT>
void iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::updateParameters() {
    values_lengths.ee_x = valuesGetter_lengths -> getValue_ee_x();
}

template <typename TRAIT>
iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link1_X_fr_FancyBase::Type_fr_link1_X_fr_FancyBase()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link1_X_fr_FancyBase& iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link1_X_fr_FancyBase::update(const JState& q) {
    Scalar s_q_jA_;
    Scalar c_q_jA_;
    
    s_q_jA_ = TRAIT::sin( q(JA));
    c_q_jA_ = TRAIT::cos( q(JA));
    
    (*this)(0,0) =  c_q_jA_;
    (*this)(0,1) =  s_q_jA_;
    (*this)(1,0) = - s_q_jA_;
    (*this)(1,1) =  c_q_jA_;
    (*this)(3,3) =  c_q_jA_;
    (*this)(3,4) =  s_q_jA_;
    (*this)(4,3) = - s_q_jA_;
    (*this)(4,4) =  c_q_jA_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_FancyBase_X_fr_link1::Type_fr_FancyBase_X_fr_link1()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_FancyBase_X_fr_link1& iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_FancyBase_X_fr_link1::update(const JState& q) {
    Scalar s_q_jA_;
    Scalar c_q_jA_;
    
    s_q_jA_ = TRAIT::sin( q(JA));
    c_q_jA_ = TRAIT::cos( q(JA));
    
    (*this)(0,0) =  c_q_jA_;
    (*this)(0,1) = - s_q_jA_;
    (*this)(1,0) =  s_q_jA_;
    (*this)(1,1) =  c_q_jA_;
    (*this)(3,3) =  c_q_jA_;
    (*this)(3,4) = - s_q_jA_;
    (*this)(4,3) =  s_q_jA_;
    (*this)(4,4) =  c_q_jA_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link2_X_fr_link1::Type_fr_link2_X_fr_link1(const Params_lengths& _lengths_values)
    : lengths_values(& _lengths_values)
{
    (*this)(0,0) = 1;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = - 1;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,3) = 1;
    (*this)(3,4) = 0;
    (*this)(3,5) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = - 1;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link2_X_fr_link1& iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link2_X_fr_link1::update(const JState& q) {
    
    
    (*this)(3,2) = - q(JB);
    (*this)(4,0) = - q(JB);
    (*this)(4,1) =  lengths_values -> ee_x;
    (*this)(5,2) =  lengths_values -> ee_x;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link1_X_fr_link2::Type_fr_link1_X_fr_link2(const Params_lengths& _lengths_values)
    : lengths_values(& _lengths_values)
{
    (*this)(0,0) = 1;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = - 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
    (*this)(3,4) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = 1;
    (*this)(5,1) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = - 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link1_X_fr_link2& iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link1_X_fr_link2::update(const JState& q) {
    
    
    (*this)(3,1) = - q(JB);
    (*this)(4,1) =  lengths_values -> ee_x;
    (*this)(5,0) = - q(JB);
    (*this)(5,2) =  lengths_values -> ee_x;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link3_X_fr_link2::Type_fr_link3_X_fr_link2()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link3_X_fr_link2& iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link3_X_fr_link2::update(const JState& q) {
    Scalar s_q_jC_;
    Scalar c_q_jC_;
    
    s_q_jC_ = TRAIT::sin( q(JC));
    c_q_jC_ = TRAIT::cos( q(JC));
    
    (*this)(0,0) =  c_q_jC_;
    (*this)(0,1) =  s_q_jC_;
    (*this)(1,0) = - s_q_jC_;
    (*this)(1,1) =  c_q_jC_;
    (*this)(3,0) = - s_q_jC_;
    (*this)(3,1) =  c_q_jC_;
    (*this)(3,3) =  c_q_jC_;
    (*this)(3,4) =  s_q_jC_;
    (*this)(4,0) = - c_q_jC_;
    (*this)(4,1) = - s_q_jC_;
    (*this)(4,3) = - s_q_jC_;
    (*this)(4,4) =  c_q_jC_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link2_X_fr_link3::Type_fr_link2_X_fr_link3()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link2_X_fr_link3& iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link2_X_fr_link3::update(const JState& q) {
    Scalar s_q_jC_;
    Scalar c_q_jC_;
    
    s_q_jC_ = TRAIT::sin( q(JC));
    c_q_jC_ = TRAIT::cos( q(JC));
    
    (*this)(0,0) =  c_q_jC_;
    (*this)(0,1) = - s_q_jC_;
    (*this)(1,0) =  s_q_jC_;
    (*this)(1,1) =  c_q_jC_;
    (*this)(3,0) = - s_q_jC_;
    (*this)(3,1) = - c_q_jC_;
    (*this)(3,3) =  c_q_jC_;
    (*this)(3,4) = - s_q_jC_;
    (*this)(4,0) =  c_q_jC_;
    (*this)(4,1) = - s_q_jC_;
    (*this)(4,3) =  s_q_jC_;
    (*this)(4,4) =  c_q_jC_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link4_X_fr_link3::Type_fr_link4_X_fr_link3()
{
    (*this)(0,0) = 1;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1.0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = - 1.0;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,3) = 1;
    (*this)(3,4) = 0;
    (*this)(3,5) = 0;
    (*this)(4,1) = - 1.0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = 1;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = - 1.0;
    (*this)(5,3) = 0;
    (*this)(5,4) = - 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link4_X_fr_link3& iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link4_X_fr_link3::update(const JState& q) {
    
    
    (*this)(3,2) =  q(JD);
    (*this)(4,0) = - q(JD);
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link3_X_fr_link4::Type_fr_link3_X_fr_link4()
{
    (*this)(0,0) = 1;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = - 1;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
    (*this)(3,4) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = - 1.0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = - 1.0;
    (*this)(5,1) = 0;
    (*this)(5,2) = - 1.0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 1.0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link3_X_fr_link4& iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link3_X_fr_link4::update(const JState& q) {
    
    
    (*this)(3,1) = - q(JD);
    (*this)(5,0) =  q(JD);
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link5_X_fr_link4::Type_fr_link5_X_fr_link4()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link5_X_fr_link4& iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link5_X_fr_link4::update(const JState& q) {
    Scalar s_q_jE_;
    Scalar c_q_jE_;
    
    s_q_jE_ = TRAIT::sin( q(JE));
    c_q_jE_ = TRAIT::cos( q(JE));
    
    (*this)(0,0) =  c_q_jE_;
    (*this)(0,1) =  s_q_jE_;
    (*this)(1,0) = - s_q_jE_;
    (*this)(1,1) =  c_q_jE_;
    (*this)(3,0) = - s_q_jE_;
    (*this)(3,1) =  c_q_jE_;
    (*this)(3,3) =  c_q_jE_;
    (*this)(3,4) =  s_q_jE_;
    (*this)(4,0) = - c_q_jE_;
    (*this)(4,1) = - s_q_jE_;
    (*this)(4,3) = - s_q_jE_;
    (*this)(4,4) =  c_q_jE_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link4_X_fr_link5::Type_fr_link4_X_fr_link5()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link4_X_fr_link5& iit::Fancy::tpl::MotionTransforms<TRAIT>::Type_fr_link4_X_fr_link5::update(const JState& q) {
    Scalar s_q_jE_;
    Scalar c_q_jE_;
    
    s_q_jE_ = TRAIT::sin( q(JE));
    c_q_jE_ = TRAIT::cos( q(JE));
    
    (*this)(0,0) =  c_q_jE_;
    (*this)(0,1) = - s_q_jE_;
    (*this)(1,0) =  s_q_jE_;
    (*this)(1,1) =  c_q_jE_;
    (*this)(3,0) = - s_q_jE_;
    (*this)(3,1) = - c_q_jE_;
    (*this)(3,3) =  c_q_jE_;
    (*this)(3,4) = - s_q_jE_;
    (*this)(4,0) =  c_q_jE_;
    (*this)(4,1) = - s_q_jE_;
    (*this)(4,3) =  s_q_jE_;
    (*this)(4,4) =  c_q_jE_;
    return *this;
}

template <typename TRAIT>
iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link1_X_fr_FancyBase::Type_fr_link1_X_fr_FancyBase()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link1_X_fr_FancyBase& iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link1_X_fr_FancyBase::update(const JState& q) {
    Scalar s_q_jA_;
    Scalar c_q_jA_;
    
    s_q_jA_ = TRAIT::sin( q(JA));
    c_q_jA_ = TRAIT::cos( q(JA));
    
    (*this)(0,0) =  c_q_jA_;
    (*this)(0,1) =  s_q_jA_;
    (*this)(1,0) = - s_q_jA_;
    (*this)(1,1) =  c_q_jA_;
    (*this)(3,3) =  c_q_jA_;
    (*this)(3,4) =  s_q_jA_;
    (*this)(4,3) = - s_q_jA_;
    (*this)(4,4) =  c_q_jA_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_FancyBase_X_fr_link1::Type_fr_FancyBase_X_fr_link1()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_FancyBase_X_fr_link1& iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_FancyBase_X_fr_link1::update(const JState& q) {
    Scalar s_q_jA_;
    Scalar c_q_jA_;
    
    s_q_jA_ = TRAIT::sin( q(JA));
    c_q_jA_ = TRAIT::cos( q(JA));
    
    (*this)(0,0) =  c_q_jA_;
    (*this)(0,1) = - s_q_jA_;
    (*this)(1,0) =  s_q_jA_;
    (*this)(1,1) =  c_q_jA_;
    (*this)(3,3) =  c_q_jA_;
    (*this)(3,4) = - s_q_jA_;
    (*this)(4,3) =  s_q_jA_;
    (*this)(4,4) =  c_q_jA_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link2_X_fr_link1::Type_fr_link2_X_fr_link1(const Params_lengths& _lengths_values)
    : lengths_values(& _lengths_values)
{
    (*this)(0,0) = 1;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = - 1;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
    (*this)(3,4) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = - 1;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link2_X_fr_link1& iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link2_X_fr_link1::update(const JState& q) {
    
    
    (*this)(0,5) = - q(JB);
    (*this)(1,3) = - q(JB);
    (*this)(1,4) =  lengths_values -> ee_x;
    (*this)(2,5) =  lengths_values -> ee_x;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link1_X_fr_link2::Type_fr_link1_X_fr_link2(const Params_lengths& _lengths_values)
    : lengths_values(& _lengths_values)
{
    (*this)(0,0) = 1;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1;
    (*this)(1,3) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = - 1;
    (*this)(2,2) = 0;
    (*this)(2,4) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
    (*this)(3,4) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = 1;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = - 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link1_X_fr_link2& iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link1_X_fr_link2::update(const JState& q) {
    
    
    (*this)(0,4) = - q(JB);
    (*this)(1,4) =  lengths_values -> ee_x;
    (*this)(2,3) = - q(JB);
    (*this)(2,5) =  lengths_values -> ee_x;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link3_X_fr_link2::Type_fr_link3_X_fr_link2()
{
    (*this)(0,2) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link3_X_fr_link2& iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link3_X_fr_link2::update(const JState& q) {
    Scalar s_q_jC_;
    Scalar c_q_jC_;
    
    s_q_jC_ = TRAIT::sin( q(JC));
    c_q_jC_ = TRAIT::cos( q(JC));
    
    (*this)(0,0) =  c_q_jC_;
    (*this)(0,1) =  s_q_jC_;
    (*this)(0,3) = - s_q_jC_;
    (*this)(0,4) =  c_q_jC_;
    (*this)(1,0) = - s_q_jC_;
    (*this)(1,1) =  c_q_jC_;
    (*this)(1,3) = - c_q_jC_;
    (*this)(1,4) = - s_q_jC_;
    (*this)(3,3) =  c_q_jC_;
    (*this)(3,4) =  s_q_jC_;
    (*this)(4,3) = - s_q_jC_;
    (*this)(4,4) =  c_q_jC_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link2_X_fr_link3::Type_fr_link2_X_fr_link3()
{
    (*this)(0,2) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link2_X_fr_link3& iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link2_X_fr_link3::update(const JState& q) {
    Scalar s_q_jC_;
    Scalar c_q_jC_;
    
    s_q_jC_ = TRAIT::sin( q(JC));
    c_q_jC_ = TRAIT::cos( q(JC));
    
    (*this)(0,0) =  c_q_jC_;
    (*this)(0,1) = - s_q_jC_;
    (*this)(0,3) = - s_q_jC_;
    (*this)(0,4) = - c_q_jC_;
    (*this)(1,0) =  s_q_jC_;
    (*this)(1,1) =  c_q_jC_;
    (*this)(1,3) =  c_q_jC_;
    (*this)(1,4) = - s_q_jC_;
    (*this)(3,3) =  c_q_jC_;
    (*this)(3,4) = - s_q_jC_;
    (*this)(4,3) =  s_q_jC_;
    (*this)(4,4) =  c_q_jC_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link4_X_fr_link3::Type_fr_link4_X_fr_link3()
{
    (*this)(0,0) = 1;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1;
    (*this)(1,4) = - 1.0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = - 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = - 1.0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
    (*this)(3,4) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = 1.0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = - 1.0;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link4_X_fr_link3& iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link4_X_fr_link3::update(const JState& q) {
    
    
    (*this)(0,5) =  q(JD);
    (*this)(1,3) = - q(JD);
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link3_X_fr_link4::Type_fr_link3_X_fr_link4()
{
    (*this)(0,0) = 1;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,5) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = - 1.0;
    (*this)(1,3) = 0;
    (*this)(1,4) = - 1.0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 1.0;
    (*this)(2,2) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = - 1.0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
    (*this)(3,4) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,3) = 0;
    (*this)(4,4) = 0;
    (*this)(4,5) = - 1;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 1;
    (*this)(5,5) = 0;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link3_X_fr_link4& iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link3_X_fr_link4::update(const JState& q) {
    
    
    (*this)(0,4) = - q(JD);
    (*this)(2,3) =  q(JD);
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link5_X_fr_link4::Type_fr_link5_X_fr_link4()
{
    (*this)(0,2) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link5_X_fr_link4& iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link5_X_fr_link4::update(const JState& q) {
    Scalar s_q_jE_;
    Scalar c_q_jE_;
    
    s_q_jE_ = TRAIT::sin( q(JE));
    c_q_jE_ = TRAIT::cos( q(JE));
    
    (*this)(0,0) =  c_q_jE_;
    (*this)(0,1) =  s_q_jE_;
    (*this)(0,3) = - s_q_jE_;
    (*this)(0,4) =  c_q_jE_;
    (*this)(1,0) = - s_q_jE_;
    (*this)(1,1) =  c_q_jE_;
    (*this)(1,3) = - c_q_jE_;
    (*this)(1,4) = - s_q_jE_;
    (*this)(3,3) =  c_q_jE_;
    (*this)(3,4) =  s_q_jE_;
    (*this)(4,3) = - s_q_jE_;
    (*this)(4,4) =  c_q_jE_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link4_X_fr_link5::Type_fr_link4_X_fr_link5()
{
    (*this)(0,2) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,5) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,2) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link4_X_fr_link5& iit::Fancy::tpl::ForceTransforms<TRAIT>::Type_fr_link4_X_fr_link5::update(const JState& q) {
    Scalar s_q_jE_;
    Scalar c_q_jE_;
    
    s_q_jE_ = TRAIT::sin( q(JE));
    c_q_jE_ = TRAIT::cos( q(JE));
    
    (*this)(0,0) =  c_q_jE_;
    (*this)(0,1) = - s_q_jE_;
    (*this)(0,3) = - s_q_jE_;
    (*this)(0,4) = - c_q_jE_;
    (*this)(1,0) =  s_q_jE_;
    (*this)(1,1) =  c_q_jE_;
    (*this)(1,3) =  c_q_jE_;
    (*this)(1,4) = - s_q_jE_;
    (*this)(3,3) =  c_q_jE_;
    (*this)(3,4) = - s_q_jE_;
    (*this)(4,3) =  s_q_jE_;
    (*this)(4,4) =  c_q_jE_;
    return *this;
}

template <typename TRAIT>
iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link1_X_fr_FancyBase::Type_fr_link1_X_fr_FancyBase()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link1_X_fr_FancyBase& iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link1_X_fr_FancyBase::update(const JState& q) {
    Scalar s_q_jA_;
    Scalar c_q_jA_;
    
    s_q_jA_ = TRAIT::sin( q(JA));
    c_q_jA_ = TRAIT::cos( q(JA));
    
    (*this)(0,0) =  c_q_jA_;
    (*this)(0,1) =  s_q_jA_;
    (*this)(1,0) = - s_q_jA_;
    (*this)(1,1) =  c_q_jA_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_FancyBase_X_fr_link1::Type_fr_FancyBase_X_fr_link1()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_FancyBase_X_fr_link1& iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_FancyBase_X_fr_link1::update(const JState& q) {
    Scalar s_q_jA_;
    Scalar c_q_jA_;
    
    s_q_jA_ = TRAIT::sin( q(JA));
    c_q_jA_ = TRAIT::cos( q(JA));
    
    (*this)(0,0) =  c_q_jA_;
    (*this)(0,1) = - s_q_jA_;
    (*this)(1,0) =  s_q_jA_;
    (*this)(1,1) =  c_q_jA_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link2_X_fr_link1::Type_fr_link2_X_fr_link1(const Params_lengths& _lengths_values)
    : lengths_values(& _lengths_values)
{
    (*this)(0,0) = 1;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = - 1;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 1;
    (*this)(2,2) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link2_X_fr_link1& iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link2_X_fr_link1::update(const JState& q) {
    
    
    (*this)(0,3) = - lengths_values -> ee_x;
    (*this)(2,3) = - q(JB);
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link1_X_fr_link2::Type_fr_link1_X_fr_link2(const Params_lengths& _lengths_values)
    : lengths_values(& _lengths_values)
{
    (*this)(0,0) = 1;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1;
    (*this)(2,0) = 0;
    (*this)(2,1) = - 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link1_X_fr_link2& iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link1_X_fr_link2::update(const JState& q) {
    
    
    (*this)(0,3) =  lengths_values -> ee_x;
    (*this)(1,3) =  q(JB);
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link3_X_fr_link2::Type_fr_link3_X_fr_link2()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = - 1.0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link3_X_fr_link2& iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link3_X_fr_link2::update(const JState& q) {
    Scalar s_q_jC_;
    Scalar c_q_jC_;
    
    s_q_jC_ = TRAIT::sin( q(JC));
    c_q_jC_ = TRAIT::cos( q(JC));
    
    (*this)(0,0) =  c_q_jC_;
    (*this)(0,1) =  s_q_jC_;
    (*this)(1,0) = - s_q_jC_;
    (*this)(1,1) =  c_q_jC_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link2_X_fr_link3::Type_fr_link2_X_fr_link3()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 1.0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link2_X_fr_link3& iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link2_X_fr_link3::update(const JState& q) {
    Scalar s_q_jC_;
    Scalar c_q_jC_;
    
    s_q_jC_ = TRAIT::sin( q(JC));
    c_q_jC_ = TRAIT::cos( q(JC));
    
    (*this)(0,0) =  c_q_jC_;
    (*this)(0,1) = - s_q_jC_;
    (*this)(1,0) =  s_q_jC_;
    (*this)(1,1) =  c_q_jC_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link4_X_fr_link3::Type_fr_link4_X_fr_link3()
{
    (*this)(0,0) = 1;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(0,3) = - 1.0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = 1;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = - 1;
    (*this)(2,2) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link4_X_fr_link3& iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link4_X_fr_link3::update(const JState& q) {
    
    
    (*this)(2,3) = - q(JD);
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link3_X_fr_link4::Type_fr_link3_X_fr_link4()
{
    (*this)(0,0) = 1.0;
    (*this)(0,1) = 0;
    (*this)(0,2) = 0;
    (*this)(0,3) = 1.0;
    (*this)(1,0) = 0;
    (*this)(1,1) = 0;
    (*this)(1,2) = - 1;
    (*this)(2,0) = 0;
    (*this)(2,1) = 1;
    (*this)(2,2) = 0;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link3_X_fr_link4& iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link3_X_fr_link4::update(const JState& q) {
    
    
    (*this)(1,3) = - q(JD);
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link5_X_fr_link4::Type_fr_link5_X_fr_link4()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = - 1.0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link5_X_fr_link4& iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link5_X_fr_link4::update(const JState& q) {
    Scalar s_q_jE_;
    Scalar c_q_jE_;
    
    s_q_jE_ = TRAIT::sin( q(JE));
    c_q_jE_ = TRAIT::cos( q(JE));
    
    (*this)(0,0) =  c_q_jE_;
    (*this)(0,1) =  s_q_jE_;
    (*this)(1,0) = - s_q_jE_;
    (*this)(1,1) =  c_q_jE_;
    return *this;
}
template <typename TRAIT>
iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link4_X_fr_link5::Type_fr_link4_X_fr_link5()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 1.0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1;
}
template <typename TRAIT>
const typename iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link4_X_fr_link5& iit::Fancy::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link4_X_fr_link5::update(const JState& q) {
    Scalar s_q_jE_;
    Scalar c_q_jE_;
    
    s_q_jE_ = TRAIT::sin( q(JE));
    c_q_jE_ = TRAIT::cos( q(JE));
    
    (*this)(0,0) =  c_q_jE_;
    (*this)(0,1) = - s_q_jE_;
    (*this)(1,0) =  s_q_jE_;
    (*this)(1,1) =  c_q_jE_;
    return *this;
}

