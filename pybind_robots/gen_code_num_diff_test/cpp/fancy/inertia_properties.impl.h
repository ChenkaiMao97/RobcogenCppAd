template <typename TRAIT>
iit::Fancy::dyn::tpl::InertiaProperties<TRAIT>::InertiaProperties()
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

    com_link2 = iit::rbd::Vector3d(0.0,0.0,0.5).cast<Scalar>();
    tensor_link2.fill(
        Scalar(1.0),
        com_link2,
        rbd::Utils::buildInertiaTensor(
                Scalar(0.33458),
                Scalar(0.33458),
                Scalar(0.0025),
                Scalar(0.0),
                Scalar(0.0),
                Scalar(0.0)) );

    com_link3 = iit::rbd::Vector3d(0.5,0.0,0.0).cast<Scalar>();
    tensor_link3.fill(
        Scalar(1.0),
        com_link3,
        rbd::Utils::buildInertiaTensor(
                Scalar(0.0025),
                Scalar(0.33458),
                Scalar(0.33458),
                Scalar(0.0),
                Scalar(0.0),
                Scalar(0.0)) );

    com_link4 = iit::rbd::Vector3d(0.0,0.0,0.5).cast<Scalar>();
    tensor_link4.fill(
        Scalar(1.0),
        com_link4,
        rbd::Utils::buildInertiaTensor(
                Scalar(0.33458),
                Scalar(0.33458),
                Scalar(0.0025),
                Scalar(0.0),
                Scalar(0.0),
                Scalar(0.0)) );

    com_link5 = iit::rbd::Vector3d(0.5,0.0,0.0).cast<Scalar>();
    tensor_link5.fill(
        Scalar(1.0),
        com_link5,
        rbd::Utils::buildInertiaTensor(
                Scalar(0.0025),
                Scalar(0.33458),
                Scalar(0.33458),
                Scalar(0.0),
                Scalar(0.0),
                Scalar(0.0)) );

}

