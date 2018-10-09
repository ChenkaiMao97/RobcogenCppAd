function tau = inverseDynamics(ip, xm, qd, qdd, q)

if nargin == 5   % the joint status is also an argument
    xm = updateMotionTransforms(xm, q);
end

g = 9.81;


% First pass, link 'link1'
link1_v = zeros(6,1);
link1_a = zeros(6,1);

link1_a = xm.fr_link1_XM_fr_AcrobotBase(:,6) * g; % TODO hide 6
link1_a(3) += qdd(1);
link1_v(3) = qd(1);
vcross = vcross_mx(link1_v);

link1_f = ip.lf_link1.tensor6D * link1_a + (( -vcross' * ip.lf_link1.tensor6D)(:,3) * qd(1));

% First pass, link 'link2'
link2_v = zeros(6,1);
link2_a = zeros(6,1);

link2_v = ((xm.fr_link2_XM_fr_link1) * link1_v);
link2_v(3) += qd(2);

vcross = vcross_mx(link2_v);

link2_a = xm.fr_link2_XM_fr_link1 * link1_a + (vcross(:,3) * qd(2));
link2_a(3) += qdd(2);

link2_f = ip.lf_link2.tensor6D * link2_a + (-vcross' * ip.lf_link2.tensor6D * link2_v);

%
% Pass 2. Compute the joint torques while back propagating the spatial forces
%
tau = zeros(2,1);
% Link 'link2'
tau(2) = link2_f(3);
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
