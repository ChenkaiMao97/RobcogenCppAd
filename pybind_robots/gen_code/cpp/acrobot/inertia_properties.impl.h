template <typename TRAIT>
iit::Acrobot::dyn::tpl::InertiaProperties<TRAIT>::InertiaProperties()
{
    com_link1 = iit::rbd::Vector3d(0.5,0.0,0.0).cast<Scalar>();
    tensor_link1.fill(
        Scalar(1.0),
        com_link1,
        rbd::Utils::buildInertiaTensor(
                Scalar(0.0025),
                Scalar(0.33458),
                Scalar(0.33458),
                Scalar(0.0),
                Scalar(0.0),
                Scalar(0.0)) );

    com_link2 = iit::rbd::Vector3d(0.5,0.0,0.0).cast<Scalar>();
    tensor_link2.fill(
        Scalar(1.0),
        com_link2,
        rbd::Utils::buildInertiaTensor(
                Scalar(0.0025),
                Scalar(0.33458),
                Scalar(0.33458),
                Scalar(0.0),
                Scalar(0.0),
                Scalar(0.0)) );

}

