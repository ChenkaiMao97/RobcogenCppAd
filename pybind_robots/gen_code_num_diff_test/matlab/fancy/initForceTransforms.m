function tr = initForceTransforms()

tr.fr_link1_XF_fr_FancyBase = zeros(6, 6);
tr.fr_link1_XF_fr_FancyBase(3,3) = 1;
tr.fr_link1_XF_fr_FancyBase(6,6) = 1;

tr.fr_FancyBase_XF_fr_link1 = zeros(6, 6);
tr.fr_FancyBase_XF_fr_link1(3,3) = 1;
tr.fr_FancyBase_XF_fr_link1(6,6) = 1;

tr.fr_link2_XF_fr_link1 = zeros(6, 6);
tr.fr_link2_XF_fr_link1(1,1) = 1;
tr.fr_link2_XF_fr_link1(2,3) = - 1;
tr.fr_link2_XF_fr_link1(3,2) = 1;
tr.fr_link2_XF_fr_link1(4,4) = 1;
tr.fr_link2_XF_fr_link1(5,6) = - 1;
tr.fr_link2_XF_fr_link1(6,5) = 1;

tr.fr_link1_XF_fr_link2 = zeros(6, 6);
tr.fr_link1_XF_fr_link2(1,1) = 1;
tr.fr_link1_XF_fr_link2(2,3) = 1;
tr.fr_link1_XF_fr_link2(3,2) = - 1;
tr.fr_link1_XF_fr_link2(4,4) = 1;
tr.fr_link1_XF_fr_link2(5,6) = 1;
tr.fr_link1_XF_fr_link2(6,5) = - 1;

tr.fr_link3_XF_fr_link2 = zeros(6, 6);
tr.fr_link3_XF_fr_link2(3,3) = 1;
tr.fr_link3_XF_fr_link2(6,6) = 1;

tr.fr_link2_XF_fr_link3 = zeros(6, 6);
tr.fr_link2_XF_fr_link3(3,3) = 1;
tr.fr_link2_XF_fr_link3(6,6) = 1;

tr.fr_link4_XF_fr_link3 = zeros(6, 6);
tr.fr_link4_XF_fr_link3(1,1) = 1;
tr.fr_link4_XF_fr_link3(2,3) = 1;
tr.fr_link4_XF_fr_link3(2,5) = - 1.0;
tr.fr_link4_XF_fr_link3(3,2) = - 1;
tr.fr_link4_XF_fr_link3(3,6) = - 1.0;
tr.fr_link4_XF_fr_link3(4,4) = 1;
tr.fr_link4_XF_fr_link3(5,6) = 1.0;
tr.fr_link4_XF_fr_link3(6,5) = - 1.0;

tr.fr_link3_XF_fr_link4 = zeros(6, 6);
tr.fr_link3_XF_fr_link4(1,1) = 1;
tr.fr_link3_XF_fr_link4(2,3) = - 1.0;
tr.fr_link3_XF_fr_link4(2,5) = - 1.0;
tr.fr_link3_XF_fr_link4(3,2) = 1.0;
tr.fr_link3_XF_fr_link4(3,6) = - 1.0;
tr.fr_link3_XF_fr_link4(4,4) = 1;
tr.fr_link3_XF_fr_link4(5,6) = - 1;
tr.fr_link3_XF_fr_link4(6,5) = 1;

tr.fr_link5_XF_fr_link4 = zeros(6, 6);
tr.fr_link5_XF_fr_link4(3,3) = 1;
tr.fr_link5_XF_fr_link4(6,6) = 1;

tr.fr_link4_XF_fr_link5 = zeros(6, 6);
tr.fr_link4_XF_fr_link5(3,3) = 1;
tr.fr_link4_XF_fr_link5(6,6) = 1;

