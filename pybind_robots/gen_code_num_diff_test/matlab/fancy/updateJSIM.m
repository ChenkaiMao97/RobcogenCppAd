function H = updateJSIM(inertia_props, force_transforms)

% Initialization of the composite-inertia matrices
Ic_link1 = inertia_props.lf_link1.tensor6D;
Ic_link2 = inertia_props.lf_link2.tensor6D;
Ic_link3 = inertia_props.lf_link3.tensor6D;
Ic_link4 = inertia_props.lf_link4.tensor6D;
Ic_link5 = inertia_props.lf_link5.tensor6D;

% "Bottom-up" loop to update the inertia-composite property of each link,
%  for the current configuration

% Link link5
Ic_link4 = Ic_link4 + force_transforms.fr_link4_XF_fr_link5 * Ic_link5 * force_transforms.fr_link4_XF_fr_link5';

F = Ic_link5(:,3);
H(5, 5) = F(3);

F = force_transforms.fr_link4_XF_fr_link5 * F;
H(4, 5) = H(5, 4) = F(6);

F = force_transforms.fr_link3_XF_fr_link4 * F;
H(3, 5) = H(5, 3) = F(3);

F = force_transforms.fr_link2_XF_fr_link3 * F;
H(2, 5) = H(5, 2) = F(6);

F = force_transforms.fr_link1_XF_fr_link2 * F;
H(1, 5) = H(5, 1) = F(3);


% Link link4
Ic_link3 = Ic_link3 + force_transforms.fr_link3_XF_fr_link4 * Ic_link4 * force_transforms.fr_link3_XF_fr_link4';

F = Ic_link4(:,6);
H(4, 4) = F(6);

F = force_transforms.fr_link3_XF_fr_link4 * F;
H(3, 4) = H(4, 3) = F(3);

F = force_transforms.fr_link2_XF_fr_link3 * F;
H(2, 4) = H(4, 2) = F(6);

F = force_transforms.fr_link1_XF_fr_link2 * F;
H(1, 4) = H(4, 1) = F(3);


% Link link3
Ic_link2 = Ic_link2 + force_transforms.fr_link2_XF_fr_link3 * Ic_link3 * force_transforms.fr_link2_XF_fr_link3';

F = Ic_link3(:,3);
H(3, 3) = F(3);

F = force_transforms.fr_link2_XF_fr_link3 * F;
H(2, 3) = H(3, 2) = F(6);

F = force_transforms.fr_link1_XF_fr_link2 * F;
H(1, 3) = H(3, 1) = F(3);


% Link link2
Ic_link1 = Ic_link1 + force_transforms.fr_link1_XF_fr_link2 * Ic_link2 * force_transforms.fr_link1_XF_fr_link2';

F = Ic_link2(:,6);
H(2, 2) = F(6);

F = force_transforms.fr_link1_XF_fr_link2 * F;
H(1, 2) = H(2, 1) = F(3);


% Link link1

F = Ic_link1(:,3);
H(1, 1) = F(3);

