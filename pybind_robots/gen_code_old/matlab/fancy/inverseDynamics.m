function tau = inverseDynamics(ip, xm, qd, qdd, q)

if nargin == 5   % the joint status is also an argument
    xm = updateMotionTransforms(xm, q);
end

g = 9.81;


% First pass, link 'link1'
link1_v = zeros(6,1);
link1_a = zeros(6,1);

link1_a = xm.fr_link1_XM_fr_FancyBase(:,6) * g; % TODO hide 6
link1_a(3) += qdd(1);
link1_v(3) = qd(1);
vcross = vcross_mx(link1_v);

link1_f = ip.lf_link1.tensor6D * link1_a + (( -vcross' * ip.lf_link1.tensor6D)(:,3) * qd(1));

% First pass, link 'link2'
link2_v = zeros(6,1);
link2_a = zeros(6,1);

link2_v = ((xm.fr_link2_XM_fr_link1) * link1_v);
link2_v(6) += qd(2);

vcross = vcross_mx(link2_v);

link2_a = xm.fr_link2_XM_fr_link1 * link1_a + (vcross(:,6) * qd(2));
link2_a(6) += qdd(2);

link2_f = ip.lf_link2.tensor6D * link2_a + (-vcross' * ip.lf_link2.tensor6D * link2_v);

% First pass, link 'link3'
link3_v = zeros(6,1);
link3_a = zeros(6,1);

link3_v = ((xm.fr_link3_XM_fr_link2) * link2_v);
link3_v(3) += qd(3);

vcross = vcross_mx(link3_v);

link3_a = xm.fr_link3_XM_fr_link2 * link2_a + (vcross(:,3) * qd(3));
link3_a(3) += qdd(3);

link3_f = ip.lf_link3.tensor6D * link3_a + (-vcross' * ip.lf_link3.tensor6D * link3_v);

% First pass, link 'link4'
link4_v = zeros(6,1);
link4_a = zeros(6,1);

link4_v = ((xm.fr_link4_XM_fr_link3) * link3_v);
link4_v(6) += qd(4);

vcross = vcross_mx(link4_v);

link4_a = xm.fr_link4_XM_fr_link3 * link3_a + (vcross(:,6) * qd(4));
link4_a(6) += qdd(4);

link4_f = ip.lf_link4.tensor6D * link4_a + (-vcross' * ip.lf_link4.tensor6D * link4_v);

% First pass, link 'link5'
link5_v = zeros(6,1);
link5_a = zeros(6,1);

link5_v = ((xm.fr_link5_XM_fr_link4) * link4_v);
link5_v(3) += qd(5);

vcross = vcross_mx(link5_v);

link5_a = xm.fr_link5_XM_fr_link4 * link4_a + (vcross(:,3) * qd(5));
link5_a(3) += qdd(5);

link5_f = ip.lf_link5.tensor6D * link5_a + (-vcross' * ip.lf_link5.tensor6D * link5_v);

%
% Pass 2. Compute the joint torques while back propagating the spatial forces
%
tau = zeros(5,1);
% Link 'link5'
tau(5) = link5_f(3);
link4_f = link4_f + xm.fr_link5_XM_fr_link4' * link5_f;
% Link 'link4'
tau(4) = link4_f(6);
link3_f = link3_f + xm.fr_link4_XM_fr_link3' * link4_f;
% Link 'link3'
tau(3) = link3_f(3);
link2_f = link2_f + xm.fr_link3_XM_fr_link2' * link3_f;
% Link 'link2'
tau(2) = link2_f(6);
link1_f = link1_f + xm.fr_link2_XM_fr_link1' * link2_f;
% Link 'link1'
tau(1) = link1_f(3);

function vc = vcross_mx(v)
    vc = [   0    -v(3)  v(2)   0     0     0    ;
             v(3)  0    -v(1)   0     0     0    ;
            -v(2)  v(1)  0      0     0     0    ;
             0    -v(6)  v(5)   0    -v(3)  v(2) ;
             v(6)  0    -v(4)   v(3)  0    -v(1) ;
            -v(5)  v(4)  0     -v(2)  v(1)  0    ];
