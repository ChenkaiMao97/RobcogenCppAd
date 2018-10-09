function out = updateForceTransforms(tr, q, params)

s__q_jA = sin( q(1));
s__q_jC = sin( q(3));
s__q_jE = sin( q(5));
c__q_jA = cos( q(1));
c__q_jC = cos( q(3));
c__q_jE = cos( q(5));


tr.fr_link1_XF_fr_FancyBase(1,1) =  c__q_jA;
tr.fr_link1_XF_fr_FancyBase(1,2) =  s__q_jA;
tr.fr_link1_XF_fr_FancyBase(2,1) = - s__q_jA;
tr.fr_link1_XF_fr_FancyBase(2,2) =  c__q_jA;
tr.fr_link1_XF_fr_FancyBase(4,4) =  c__q_jA;
tr.fr_link1_XF_fr_FancyBase(4,5) =  s__q_jA;
tr.fr_link1_XF_fr_FancyBase(5,4) = - s__q_jA;
tr.fr_link1_XF_fr_FancyBase(5,5) =  c__q_jA;



tr.fr_FancyBase_XF_fr_link1(1,1) =  c__q_jA;
tr.fr_FancyBase_XF_fr_link1(1,2) = - s__q_jA;
tr.fr_FancyBase_XF_fr_link1(2,1) =  s__q_jA;
tr.fr_FancyBase_XF_fr_link1(2,2) =  c__q_jA;
tr.fr_FancyBase_XF_fr_link1(4,4) =  c__q_jA;
tr.fr_FancyBase_XF_fr_link1(4,5) = - s__q_jA;
tr.fr_FancyBase_XF_fr_link1(5,4) =  s__q_jA;
tr.fr_FancyBase_XF_fr_link1(5,5) =  c__q_jA;



tr.fr_link2_XF_fr_link1(1,6) = - q(2);
tr.fr_link2_XF_fr_link1(2,4) = - q(2);
tr.fr_link2_XF_fr_link1(2,5) =  params.lengths.ee_x;
tr.fr_link2_XF_fr_link1(3,6) =  params.lengths.ee_x;



tr.fr_link1_XF_fr_link2(1,5) = - q(2);
tr.fr_link1_XF_fr_link2(2,5) =  params.lengths.ee_x;
tr.fr_link1_XF_fr_link2(3,4) = - q(2);
tr.fr_link1_XF_fr_link2(3,6) =  params.lengths.ee_x;



tr.fr_link3_XF_fr_link2(1,1) =  c__q_jC;
tr.fr_link3_XF_fr_link2(1,2) =  s__q_jC;
tr.fr_link3_XF_fr_link2(1,4) = - s__q_jC;
tr.fr_link3_XF_fr_link2(1,5) =  c__q_jC;
tr.fr_link3_XF_fr_link2(2,1) = - s__q_jC;
tr.fr_link3_XF_fr_link2(2,2) =  c__q_jC;
tr.fr_link3_XF_fr_link2(2,4) = - c__q_jC;
tr.fr_link3_XF_fr_link2(2,5) = - s__q_jC;
tr.fr_link3_XF_fr_link2(4,4) =  c__q_jC;
tr.fr_link3_XF_fr_link2(4,5) =  s__q_jC;
tr.fr_link3_XF_fr_link2(5,4) = - s__q_jC;
tr.fr_link3_XF_fr_link2(5,5) =  c__q_jC;



tr.fr_link2_XF_fr_link3(1,1) =  c__q_jC;
tr.fr_link2_XF_fr_link3(1,2) = - s__q_jC;
tr.fr_link2_XF_fr_link3(1,4) = - s__q_jC;
tr.fr_link2_XF_fr_link3(1,5) = - c__q_jC;
tr.fr_link2_XF_fr_link3(2,1) =  s__q_jC;
tr.fr_link2_XF_fr_link3(2,2) =  c__q_jC;
tr.fr_link2_XF_fr_link3(2,4) =  c__q_jC;
tr.fr_link2_XF_fr_link3(2,5) = - s__q_jC;
tr.fr_link2_XF_fr_link3(4,4) =  c__q_jC;
tr.fr_link2_XF_fr_link3(4,5) = - s__q_jC;
tr.fr_link2_XF_fr_link3(5,4) =  s__q_jC;
tr.fr_link2_XF_fr_link3(5,5) =  c__q_jC;



tr.fr_link4_XF_fr_link3(1,6) =  q(4);
tr.fr_link4_XF_fr_link3(2,4) = - q(4);



tr.fr_link3_XF_fr_link4(1,5) = - q(4);
tr.fr_link3_XF_fr_link4(3,4) =  q(4);



tr.fr_link5_XF_fr_link4(1,1) =  c__q_jE;
tr.fr_link5_XF_fr_link4(1,2) =  s__q_jE;
tr.fr_link5_XF_fr_link4(1,4) = - s__q_jE;
tr.fr_link5_XF_fr_link4(1,5) =  c__q_jE;
tr.fr_link5_XF_fr_link4(2,1) = - s__q_jE;
tr.fr_link5_XF_fr_link4(2,2) =  c__q_jE;
tr.fr_link5_XF_fr_link4(2,4) = - c__q_jE;
tr.fr_link5_XF_fr_link4(2,5) = - s__q_jE;
tr.fr_link5_XF_fr_link4(4,4) =  c__q_jE;
tr.fr_link5_XF_fr_link4(4,5) =  s__q_jE;
tr.fr_link5_XF_fr_link4(5,4) = - s__q_jE;
tr.fr_link5_XF_fr_link4(5,5) =  c__q_jE;



tr.fr_link4_XF_fr_link5(1,1) =  c__q_jE;
tr.fr_link4_XF_fr_link5(1,2) = - s__q_jE;
tr.fr_link4_XF_fr_link5(1,4) = - s__q_jE;
tr.fr_link4_XF_fr_link5(1,5) = - c__q_jE;
tr.fr_link4_XF_fr_link5(2,1) =  s__q_jE;
tr.fr_link4_XF_fr_link5(2,2) =  c__q_jE;
tr.fr_link4_XF_fr_link5(2,4) =  c__q_jE;
tr.fr_link4_XF_fr_link5(2,5) = - s__q_jE;
tr.fr_link4_XF_fr_link5(4,4) =  c__q_jE;
tr.fr_link4_XF_fr_link5(4,5) = - s__q_jE;
tr.fr_link4_XF_fr_link5(5,4) =  s__q_jE;
tr.fr_link4_XF_fr_link5(5,5) =  c__q_jE;





out = tr;