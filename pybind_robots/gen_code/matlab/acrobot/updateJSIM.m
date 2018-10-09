function H = updateJSIM(inertia_props, force_transforms)

% Initialization of the composite-inertia matrices
Ic_link1 = inertia_props.lf_link1.tensor6D;
Ic_link2 = inertia_props.lf_link2.tensor6D;

% "Bottom-up" loop to update the inertia-composite property of each link,
%  for the current configuration

% Link link2
Ic_link1 = Ic_link1 + force_transforms.fr_link1_XF_fr_link2 * Ic_link2 * force_transforms.fr_link1_XF_fr_link2';

F = Ic_link2(:,3);
H(2, 2) = F(3);

F = force_transforms.fr_link1_XF_fr_link2 * F;
H(1, 2) = H(2, 1) = F(3);


% Link link1

F = Ic_link1(:,3);
H(1, 1) = F(3);

