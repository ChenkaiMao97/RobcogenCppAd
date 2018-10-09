function tr = initForceTransforms()

tr.fr_link1_XF_fr_AcrobotBase = zeros(6, 6);
tr.fr_link1_XF_fr_AcrobotBase(3,3) = 1;
tr.fr_link1_XF_fr_AcrobotBase(6,6) = 1;

tr.fr_AcrobotBase_XF_fr_link1 = zeros(6, 6);
tr.fr_AcrobotBase_XF_fr_link1(3,3) = 1;
tr.fr_AcrobotBase_XF_fr_link1(6,6) = 1;

tr.fr_link2_XF_fr_link1 = zeros(6, 6);
tr.fr_link2_XF_fr_link1(3,3) = 1;
tr.fr_link2_XF_fr_link1(3,5) = - 1.0;
tr.fr_link2_XF_fr_link1(6,6) = 1.0;

tr.fr_link1_XF_fr_link2 = zeros(6, 6);
tr.fr_link1_XF_fr_link2(2,6) = - 1.0;
tr.fr_link1_XF_fr_link2(3,3) = 1.0;
tr.fr_link1_XF_fr_link2(6,6) = 1;

