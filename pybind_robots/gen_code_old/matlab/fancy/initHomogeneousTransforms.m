function tr = initHomogeneousTransforms()

tr.fr_link1_Xh_fr_FancyBase = zeros(4, 4);
tr.fr_link1_Xh_fr_FancyBase(3,3) = 1;
tr.fr_link1_Xh_fr_FancyBase(4,4) = 1;

tr.fr_FancyBase_Xh_fr_link1 = zeros(4, 4);
tr.fr_FancyBase_Xh_fr_link1(3,3) = 1;
tr.fr_FancyBase_Xh_fr_link1(4,4) = 1;

tr.fr_link2_Xh_fr_link1 = zeros(4, 4);
tr.fr_link2_Xh_fr_link1(1,1) = 1;
tr.fr_link2_Xh_fr_link1(1,4) = - 1.0;
tr.fr_link2_Xh_fr_link1(2,3) = - 1;
tr.fr_link2_Xh_fr_link1(3,2) = 1;
tr.fr_link2_Xh_fr_link1(4,4) = 1.0;

tr.fr_link1_Xh_fr_link2 = zeros(4, 4);
tr.fr_link1_Xh_fr_link2(1,1) = 1.0;
tr.fr_link1_Xh_fr_link2(1,4) = 1.0;
tr.fr_link1_Xh_fr_link2(2,3) = 1;
tr.fr_link1_Xh_fr_link2(3,2) = - 1;
tr.fr_link1_Xh_fr_link2(4,4) = 1;

tr.fr_link3_Xh_fr_link2 = zeros(4, 4);
tr.fr_link3_Xh_fr_link2(3,3) = 1;
tr.fr_link3_Xh_fr_link2(3,4) = - 1.0;
tr.fr_link3_Xh_fr_link2(4,4) = 1.0;

tr.fr_link2_Xh_fr_link3 = zeros(4, 4);
tr.fr_link2_Xh_fr_link3(3,3) = 1.0;
tr.fr_link2_Xh_fr_link3(3,4) = 1.0;
tr.fr_link2_Xh_fr_link3(4,4) = 1;

tr.fr_link4_Xh_fr_link3 = zeros(4, 4);
tr.fr_link4_Xh_fr_link3(1,1) = 1;
tr.fr_link4_Xh_fr_link3(1,4) = - 1.0;
tr.fr_link4_Xh_fr_link3(2,3) = 1;
tr.fr_link4_Xh_fr_link3(3,2) = - 1;
tr.fr_link4_Xh_fr_link3(4,4) = 1.0;

tr.fr_link3_Xh_fr_link4 = zeros(4, 4);
tr.fr_link3_Xh_fr_link4(1,1) = 1.0;
tr.fr_link3_Xh_fr_link4(1,4) = 1.0;
tr.fr_link3_Xh_fr_link4(2,3) = - 1;
tr.fr_link3_Xh_fr_link4(3,2) = 1;
tr.fr_link3_Xh_fr_link4(4,4) = 1;

tr.fr_link5_Xh_fr_link4 = zeros(4, 4);
tr.fr_link5_Xh_fr_link4(3,3) = 1;
tr.fr_link5_Xh_fr_link4(3,4) = - 1.0;
tr.fr_link5_Xh_fr_link4(4,4) = 1.0;

tr.fr_link4_Xh_fr_link5 = zeros(4, 4);
tr.fr_link4_Xh_fr_link5(3,3) = 1.0;
tr.fr_link4_Xh_fr_link5(3,4) = 1.0;
tr.fr_link4_Xh_fr_link5(4,4) = 1;

