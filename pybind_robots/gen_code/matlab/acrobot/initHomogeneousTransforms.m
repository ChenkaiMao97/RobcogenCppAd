function tr = initHomogeneousTransforms()

tr.fr_link1_Xh_fr_AcrobotBase = zeros(4, 4);
tr.fr_link1_Xh_fr_AcrobotBase(3,3) = 1;
tr.fr_link1_Xh_fr_AcrobotBase(4,4) = 1;

tr.fr_AcrobotBase_Xh_fr_link1 = zeros(4, 4);
tr.fr_AcrobotBase_Xh_fr_link1(3,3) = 1;
tr.fr_AcrobotBase_Xh_fr_link1(4,4) = 1;

tr.fr_link2_Xh_fr_link1 = zeros(4, 4);
tr.fr_link2_Xh_fr_link1(3,3) = 1;
tr.fr_link2_Xh_fr_link1(4,4) = 1.0;

tr.fr_link1_Xh_fr_link2 = zeros(4, 4);
tr.fr_link1_Xh_fr_link2(1,4) = 1.0;
tr.fr_link1_Xh_fr_link2(3,3) = 1;
tr.fr_link1_Xh_fr_link2(4,4) = 1;

