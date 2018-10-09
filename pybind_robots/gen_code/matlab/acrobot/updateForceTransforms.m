function out = updateForceTransforms(tr, q, params)

s__q_jA = sin( q(1));
s__q_jB = sin( q(2));
c__q_jA = cos( q(1));
c__q_jB = cos( q(2));


tr.fr_link1_XF_fr_AcrobotBase(1,1) =  c__q_jA;
tr.fr_link1_XF_fr_AcrobotBase(1,2) =  s__q_jA;
tr.fr_link1_XF_fr_AcrobotBase(2,1) = - s__q_jA;
tr.fr_link1_XF_fr_AcrobotBase(2,2) =  c__q_jA;
tr.fr_link1_XF_fr_AcrobotBase(4,4) =  c__q_jA;
tr.fr_link1_XF_fr_AcrobotBase(4,5) =  s__q_jA;
tr.fr_link1_XF_fr_AcrobotBase(5,4) = - s__q_jA;
tr.fr_link1_XF_fr_AcrobotBase(5,5) =  c__q_jA;



tr.fr_AcrobotBase_XF_fr_link1(1,1) =  c__q_jA;
tr.fr_AcrobotBase_XF_fr_link1(1,2) = - s__q_jA;
tr.fr_AcrobotBase_XF_fr_link1(2,1) =  s__q_jA;
tr.fr_AcrobotBase_XF_fr_link1(2,2) =  c__q_jA;
tr.fr_AcrobotBase_XF_fr_link1(4,4) =  c__q_jA;
tr.fr_AcrobotBase_XF_fr_link1(4,5) = - s__q_jA;
tr.fr_AcrobotBase_XF_fr_link1(5,4) =  s__q_jA;
tr.fr_AcrobotBase_XF_fr_link1(5,5) =  c__q_jA;



tr.fr_link2_XF_fr_link1(1,1) =  c__q_jB;
tr.fr_link2_XF_fr_link1(1,2) =  s__q_jB;
tr.fr_link2_XF_fr_link1(1,6) =  s__q_jB;
tr.fr_link2_XF_fr_link1(2,1) = - s__q_jB;
tr.fr_link2_XF_fr_link1(2,2) =  c__q_jB;
tr.fr_link2_XF_fr_link1(2,6) =  c__q_jB;
tr.fr_link2_XF_fr_link1(4,4) =  c__q_jB;
tr.fr_link2_XF_fr_link1(4,5) =  s__q_jB;
tr.fr_link2_XF_fr_link1(5,4) = - s__q_jB;
tr.fr_link2_XF_fr_link1(5,5) =  c__q_jB;



tr.fr_link1_XF_fr_link2(1,1) =  c__q_jB;
tr.fr_link1_XF_fr_link2(1,2) = - s__q_jB;
tr.fr_link1_XF_fr_link2(2,1) =  s__q_jB;
tr.fr_link1_XF_fr_link2(2,2) =  c__q_jB;
tr.fr_link1_XF_fr_link2(3,4) =  s__q_jB;
tr.fr_link1_XF_fr_link2(3,5) =  c__q_jB;
tr.fr_link1_XF_fr_link2(4,4) =  c__q_jB;
tr.fr_link1_XF_fr_link2(4,5) = - s__q_jB;
tr.fr_link1_XF_fr_link2(5,4) =  s__q_jB;
tr.fr_link1_XF_fr_link2(5,5) =  c__q_jB;





out = tr;