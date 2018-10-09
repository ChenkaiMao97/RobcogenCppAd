function out = inertiaProperties()

% Inertia parameters as written in the .kindsl model file
out.FancyBase.mass = 1.0;
out.FancyBase.tensor = ...
    [[  0.0,	-(0.0),	-(0.0)];
     [-(0.0),	  0.0 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.0]];
out.FancyBase.com = [0.0; 0.0; 0.0];

out.link1.mass = 1.0;
out.link1.tensor = ...
    [[  0.0025,	-(0.0),	-(0.0)];
     [-(0.0),	  0.33458 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.33458]];
out.link1.com = [0.5; 0.0; 0.0];

out.link2.mass = 1.0;
out.link2.tensor = ...
    [[  0.33458,	-(0.0),	-(0.0)];
     [-(0.0),	  0.33458 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.0025]];
out.link2.com = [0.0; 0.0; 0.5];

out.link3.mass = 1.0;
out.link3.tensor = ...
    [[  0.0025,	-(0.0),	-(0.0)];
     [-(0.0),	  0.33458 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.33458]];
out.link3.com = [0.5; 0.0; 0.0];

out.link4.mass = 1.0;
out.link4.tensor = ...
    [[  0.33458,	-(0.0),	-(0.0)];
     [-(0.0),	  0.33458 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.0025]];
out.link4.com = [0.0; 0.0; 0.5];

out.link5.mass = 1.0;
out.link5.tensor = ...
    [[  0.0025,	-(0.0),	-(0.0)];
     [-(0.0),	  0.33458 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.33458]];
out.link5.com = [0.5; 0.0; 0.0];


% Now the same inertia parameters expressed in the link frame (may be equal or not to
%  the previous ones, depending on the model file)
out.lf_FancyBase.mass = 1.0;
out.lf_FancyBase.tensor = ...
    [[  0.0,	-(0.0),	-(0.0)];
     [-(0.0),	  0.0 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.0]];
out.lf_FancyBase.com = [0.0; 0.0; 0.0];
com = out.lf_FancyBase.com;
block = [  0,    -com(3),  com(2);
         com(3),  0,      -com(1);
        -com(2),  com(1),  0 ] * out.lf_FancyBase.mass;
out.lf_FancyBase.tensor6D = [out.lf_FancyBase.tensor, block; block', out.lf_FancyBase.mass*eye(3)];

out.lf_link1.mass = 1.0;
out.lf_link1.tensor = ...
    [[  0.0025,	-(0.0),	-(0.0)];
     [-(0.0),	  0.33458 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.33458]];
out.lf_link1.com = [0.5; 0.0; 0.0];
com = out.lf_link1.com;
block = [  0,    -com(3),  com(2);
         com(3),  0,      -com(1);
        -com(2),  com(1),  0 ] * out.lf_link1.mass;
out.lf_link1.tensor6D = [out.lf_link1.tensor, block; block', out.lf_link1.mass*eye(3)];

out.lf_link2.mass = 1.0;
out.lf_link2.tensor = ...
    [[  0.33458,	-(0.0),	-(0.0)];
     [-(0.0),	  0.33458 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.0025]];
out.lf_link2.com = [0.0; 0.0; 0.5];
com = out.lf_link2.com;
block = [  0,    -com(3),  com(2);
         com(3),  0,      -com(1);
        -com(2),  com(1),  0 ] * out.lf_link2.mass;
out.lf_link2.tensor6D = [out.lf_link2.tensor, block; block', out.lf_link2.mass*eye(3)];

out.lf_link3.mass = 1.0;
out.lf_link3.tensor = ...
    [[  0.0025,	-(0.0),	-(0.0)];
     [-(0.0),	  0.33458 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.33458]];
out.lf_link3.com = [0.5; 0.0; 0.0];
com = out.lf_link3.com;
block = [  0,    -com(3),  com(2);
         com(3),  0,      -com(1);
        -com(2),  com(1),  0 ] * out.lf_link3.mass;
out.lf_link3.tensor6D = [out.lf_link3.tensor, block; block', out.lf_link3.mass*eye(3)];

out.lf_link4.mass = 1.0;
out.lf_link4.tensor = ...
    [[  0.33458,	-(0.0),	-(0.0)];
     [-(0.0),	  0.33458 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.0025]];
out.lf_link4.com = [0.0; 0.0; 0.5];
com = out.lf_link4.com;
block = [  0,    -com(3),  com(2);
         com(3),  0,      -com(1);
        -com(2),  com(1),  0 ] * out.lf_link4.mass;
out.lf_link4.tensor6D = [out.lf_link4.tensor, block; block', out.lf_link4.mass*eye(3)];

out.lf_link5.mass = 1.0;
out.lf_link5.tensor = ...
    [[  0.0025,	-(0.0),	-(0.0)];
     [-(0.0),	  0.33458 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.33458]];
out.lf_link5.com = [0.5; 0.0; 0.0];
com = out.lf_link5.com;
block = [  0,    -com(3),  com(2);
         com(3),  0,      -com(1);
        -com(2),  com(1),  0 ] * out.lf_link5.mass;
out.lf_link5.tensor6D = [out.lf_link5.tensor, block; block', out.lf_link5.mass*eye(3)];


% Same inertial properties expressed in a frame with origin in the COM of the link
%  oriented as the default link-frame (the COM coordinates in such a frame should
%  always be [0,0,0] ).
out.com_FancyBase.mass = 1.0;
out.com_FancyBase.tensor = ...
    [[  0.0,	-(0.0),	-(0.0)];
     [-(0.0),	  0.0 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.0]];
out.com_FancyBase.com = [0.0; 0.0; 0.0];

out.com_link1.mass = 1.0;
out.com_link1.tensor = ...
    [[  0.0025,	-(0.0),	-(0.0)];
     [-(0.0),	  0.084580004 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.084580004]];
out.com_link1.com = [0.0; 0.0; 0.0];

out.com_link2.mass = 1.0;
out.com_link2.tensor = ...
    [[  0.084580004,	-(0.0),	-(0.0)];
     [-(0.0),	  0.084580004 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.0025]];
out.com_link2.com = [0.0; 0.0; 0.0];

out.com_link3.mass = 1.0;
out.com_link3.tensor = ...
    [[  0.0025,	-(0.0),	-(0.0)];
     [-(0.0),	  0.084580004 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.084580004]];
out.com_link3.com = [0.0; 0.0; 0.0];

out.com_link4.mass = 1.0;
out.com_link4.tensor = ...
    [[  0.084580004,	-(0.0),	-(0.0)];
     [-(0.0),	  0.084580004 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.0025]];
out.com_link4.com = [0.0; 0.0; 0.0];

out.com_link5.mass = 1.0;
out.com_link5.tensor = ...
    [[  0.0025,	-(0.0),	-(0.0)];
     [-(0.0),	  0.084580004 ,	-(0.0)];
     [-(0.0),	-(0.0),	  0.084580004]];
out.com_link5.com = [0.0; 0.0; 0.0];

