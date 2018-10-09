
// Constructors
template <typename TRAIT>
iit::Acrobot::tpl::MotionTransforms<TRAIT>::MotionTransforms
    ()
     :
    fr_link1_X_fr_AcrobotBase(),
    fr_AcrobotBase_X_fr_link1(),
    fr_link2_X_fr_link1(),
    fr_link1_X_fr_link2()
{
    updateParameters();
}
template <typename TRAIT>
void iit::Acrobot::tpl::MotionTransforms<TRAIT>::updateParameters() {
}

template <typename TRAIT>
iit::Acrobot::tpl::ForceTransforms<TRAIT>::ForceTransforms
    ()
     :
    fr_link1_X_fr_AcrobotBase(),
    fr_AcrobotBase_X_fr_link1(),
    fr_link2_X_fr_link1(),
    fr_link1_X_fr_link2()
{
    updateParameters();
}
template <typename TRAIT>
void iit::Acrobot::tpl::ForceTransforms<TRAIT>::updateParameters() {
}

template <typename TRAIT>
iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::HomogeneousTransforms
    ()
     :
    fr_link1_X_fr_AcrobotBase(),
    fr_AcrobotBase_X_fr_link1(),
    fr_link2_X_fr_link1(),
    fr_link1_X_fr_link2()
{
    updateParameters();
}
template <typename TRAIT>
void iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::updateParameters() {
}

template <typename TRAIT>
iit::Acrobot::tpl::MotionTransforms<TRAIT>::Type_fr_link1_X_fr_AcrobotBase::Type_fr_link1_X_fr_AcrobotBase()
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
const typename iit::Acrobot::tpl::MotionTransforms<TRAIT>::Type_fr_link1_X_fr_AcrobotBase& iit::Acrobot::tpl::MotionTransforms<TRAIT>::Type_fr_link1_X_fr_AcrobotBase::update(const JState& q) {
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
iit::Acrobot::tpl::MotionTransforms<TRAIT>::Type_fr_AcrobotBase_X_fr_link1::Type_fr_AcrobotBase_X_fr_link1()
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
const typename iit::Acrobot::tpl::MotionTransforms<TRAIT>::Type_fr_AcrobotBase_X_fr_link1& iit::Acrobot::tpl::MotionTransforms<TRAIT>::Type_fr_AcrobotBase_X_fr_link1::update(const JState& q) {
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
iit::Acrobot::tpl::MotionTransforms<TRAIT>::Type_fr_link2_X_fr_link1::Type_fr_link2_X_fr_link1()
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
    (*this)(2,2) = 1.0;
    (*this)(2,3) = 0;
    (*this)(2,4) = 0;
    (*this)(2,5) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,5) = 0;
    (*this)(4,0) = 0;
    (*this)(4,1) = 0;
    (*this)(4,5) = 0;
    (*this)(5,0) = 0;
    (*this)(5,1) = - 1.0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1;
}
template <typename TRAIT>
const typename iit::Acrobot::tpl::MotionTransforms<TRAIT>::Type_fr_link2_X_fr_link1& iit::Acrobot::tpl::MotionTransforms<TRAIT>::Type_fr_link2_X_fr_link1::update(const JState& q) {
    Scalar s_q_jB_;
    Scalar c_q_jB_;
    
    s_q_jB_ = TRAIT::sin( q(JB));
    c_q_jB_ = TRAIT::cos( q(JB));
    
    (*this)(0,0) =  c_q_jB_;
    (*this)(0,1) =  s_q_jB_;
    (*this)(1,0) = - s_q_jB_;
    (*this)(1,1) =  c_q_jB_;
    (*this)(3,2) =  s_q_jB_;
    (*this)(3,3) =  c_q_jB_;
    (*this)(3,4) =  s_q_jB_;
    (*this)(4,2) =  c_q_jB_;
    (*this)(4,3) = - s_q_jB_;
    (*this)(4,4) =  c_q_jB_;
    return *this;
}
template <typename TRAIT>
iit::Acrobot::tpl::MotionTransforms<TRAIT>::Type_fr_link1_X_fr_link2::Type_fr_link1_X_fr_link2()
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
    (*this)(4,2) = - 1.0;
    (*this)(4,5) = 0;
    (*this)(5,2) = 0;
    (*this)(5,3) = 0;
    (*this)(5,4) = 0;
    (*this)(5,5) = 1.0;
}
template <typename TRAIT>
const typename iit::Acrobot::tpl::MotionTransforms<TRAIT>::Type_fr_link1_X_fr_link2& iit::Acrobot::tpl::MotionTransforms<TRAIT>::Type_fr_link1_X_fr_link2::update(const JState& q) {
    Scalar s_q_jB_;
    Scalar c_q_jB_;
    
    s_q_jB_ = TRAIT::sin( q(JB));
    c_q_jB_ = TRAIT::cos( q(JB));
    
    (*this)(0,0) =  c_q_jB_;
    (*this)(0,1) = - s_q_jB_;
    (*this)(1,0) =  s_q_jB_;
    (*this)(1,1) =  c_q_jB_;
    (*this)(3,3) =  c_q_jB_;
    (*this)(3,4) = - s_q_jB_;
    (*this)(4,3) =  s_q_jB_;
    (*this)(4,4) =  c_q_jB_;
    (*this)(5,0) =  s_q_jB_;
    (*this)(5,1) =  c_q_jB_;
    return *this;
}

template <typename TRAIT>
iit::Acrobot::tpl::ForceTransforms<TRAIT>::Type_fr_link1_X_fr_AcrobotBase::Type_fr_link1_X_fr_AcrobotBase()
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
const typename iit::Acrobot::tpl::ForceTransforms<TRAIT>::Type_fr_link1_X_fr_AcrobotBase& iit::Acrobot::tpl::ForceTransforms<TRAIT>::Type_fr_link1_X_fr_AcrobotBase::update(const JState& q) {
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
iit::Acrobot::tpl::ForceTransforms<TRAIT>::Type_fr_AcrobotBase_X_fr_link1::Type_fr_AcrobotBase_X_fr_link1()
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
const typename iit::Acrobot::tpl::ForceTransforms<TRAIT>::Type_fr_AcrobotBase_X_fr_link1& iit::Acrobot::tpl::ForceTransforms<TRAIT>::Type_fr_AcrobotBase_X_fr_link1::update(const JState& q) {
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
iit::Acrobot::tpl::ForceTransforms<TRAIT>::Type_fr_link2_X_fr_link1::Type_fr_link2_X_fr_link1()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(2,4) = - 1.0;
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
    (*this)(5,5) = 1.0;
}
template <typename TRAIT>
const typename iit::Acrobot::tpl::ForceTransforms<TRAIT>::Type_fr_link2_X_fr_link1& iit::Acrobot::tpl::ForceTransforms<TRAIT>::Type_fr_link2_X_fr_link1::update(const JState& q) {
    Scalar s_q_jB_;
    Scalar c_q_jB_;
    
    s_q_jB_ = TRAIT::sin( q(JB));
    c_q_jB_ = TRAIT::cos( q(JB));
    
    (*this)(0,0) =  c_q_jB_;
    (*this)(0,1) =  s_q_jB_;
    (*this)(0,5) =  s_q_jB_;
    (*this)(1,0) = - s_q_jB_;
    (*this)(1,1) =  c_q_jB_;
    (*this)(1,5) =  c_q_jB_;
    (*this)(3,3) =  c_q_jB_;
    (*this)(3,4) =  s_q_jB_;
    (*this)(4,3) = - s_q_jB_;
    (*this)(4,4) =  c_q_jB_;
    return *this;
}
template <typename TRAIT>
iit::Acrobot::tpl::ForceTransforms<TRAIT>::Type_fr_link1_X_fr_link2::Type_fr_link1_X_fr_link2()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 0;
    (*this)(0,4) = 0;
    (*this)(0,5) = 0;
    (*this)(1,2) = 0;
    (*this)(1,3) = 0;
    (*this)(1,4) = 0;
    (*this)(1,5) = - 1.0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1.0;
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
const typename iit::Acrobot::tpl::ForceTransforms<TRAIT>::Type_fr_link1_X_fr_link2& iit::Acrobot::tpl::ForceTransforms<TRAIT>::Type_fr_link1_X_fr_link2::update(const JState& q) {
    Scalar s_q_jB_;
    Scalar c_q_jB_;
    
    s_q_jB_ = TRAIT::sin( q(JB));
    c_q_jB_ = TRAIT::cos( q(JB));
    
    (*this)(0,0) =  c_q_jB_;
    (*this)(0,1) = - s_q_jB_;
    (*this)(1,0) =  s_q_jB_;
    (*this)(1,1) =  c_q_jB_;
    (*this)(2,3) =  s_q_jB_;
    (*this)(2,4) =  c_q_jB_;
    (*this)(3,3) =  c_q_jB_;
    (*this)(3,4) = - s_q_jB_;
    (*this)(4,3) =  s_q_jB_;
    (*this)(4,4) =  c_q_jB_;
    return *this;
}

template <typename TRAIT>
iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link1_X_fr_AcrobotBase::Type_fr_link1_X_fr_AcrobotBase()
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
const typename iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link1_X_fr_AcrobotBase& iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link1_X_fr_AcrobotBase::update(const JState& q) {
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
iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::Type_fr_AcrobotBase_X_fr_link1::Type_fr_AcrobotBase_X_fr_link1()
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
const typename iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::Type_fr_AcrobotBase_X_fr_link1& iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::Type_fr_AcrobotBase_X_fr_link1::update(const JState& q) {
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
iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link2_X_fr_link1::Type_fr_link2_X_fr_link1()
{
    (*this)(0,2) = 0;
    (*this)(1,2) = 0;
    (*this)(2,0) = 0;
    (*this)(2,1) = 0;
    (*this)(2,2) = 1;
    (*this)(2,3) = 0;
    (*this)(3,0) = 0;
    (*this)(3,1) = 0;
    (*this)(3,2) = 0;
    (*this)(3,3) = 1.0;
}
template <typename TRAIT>
const typename iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link2_X_fr_link1& iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link2_X_fr_link1::update(const JState& q) {
    Scalar s_q_jB_;
    Scalar c_q_jB_;
    
    s_q_jB_ = TRAIT::sin( q(JB));
    c_q_jB_ = TRAIT::cos( q(JB));
    
    (*this)(0,0) =  c_q_jB_;
    (*this)(0,1) =  s_q_jB_;
    (*this)(0,3) = - c_q_jB_;
    (*this)(1,0) = - s_q_jB_;
    (*this)(1,1) =  c_q_jB_;
    (*this)(1,3) =  s_q_jB_;
    return *this;
}
template <typename TRAIT>
iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link1_X_fr_link2::Type_fr_link1_X_fr_link2()
{
    (*this)(0,2) = 0;
    (*this)(0,3) = 1.0;
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
const typename iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link1_X_fr_link2& iit::Acrobot::tpl::HomogeneousTransforms<TRAIT>::Type_fr_link1_X_fr_link2::update(const JState& q) {
    Scalar s_q_jB_;
    Scalar c_q_jB_;
    
    s_q_jB_ = TRAIT::sin( q(JB));
    c_q_jB_ = TRAIT::cos( q(JB));
    
    (*this)(0,0) =  c_q_jB_;
    (*this)(0,1) = - s_q_jB_;
    (*this)(1,0) =  s_q_jB_;
    (*this)(1,1) =  c_q_jB_;
    return *this;
}

