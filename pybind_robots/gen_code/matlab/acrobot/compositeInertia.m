function ci = compositeInertia(ip, xf, transformsType)

% Computes the spatial composite inertia of each link of the robot.
% Arguments:
% - ip : the structure with the inertia properties
% - xf : the structure with the spatial coordinate transformation matrices
% - transformsType : a string specifying which is the type of the given
%      coordinate transforms, either velocity ('motion') or force ('force').
%      Optional argument, default is 'force'.

if nargin < 3
    transformsType = 'force';
end

%
% Initialization of the composite-inertia matrices
%
ci.link1_Ic = ip.lf_link1.tensor6D;
ci.link2_Ic = ip.lf_link2.tensor6D;

%
% Leafs-to-root pass to update the composite inertia of
%     each link, for the current configuration:
%

if strcmp(transformsType, 'motion')  % we have transforms for motion vectors

% Contribution of link link2
ci.link1_Ic = ci.link1_Ic + xf.fr_link2_XM_fr_link1' * ci.link2_Ic * xf.fr_link2_XM_fr_link1;


% Contribution of link link1


else % we have transforms for force vectors

% Contribution of link link2
ci.link1_Ic = ci.link1_Ic + xf.fr_link1_XF_fr_link2 * ci.link2_Ic * xf.fr_link1_XF_fr_link2';


% Contribution of link link1


end
