function [Hinv L Linv] = invertJSIM(H)

% The following code computes the lower triangular matrix L such that
%  H = L' L  (LTL factorization)
% Then it computes the inverse of L and the inverse of H

% LTL factorization
L = tril(H); % lower triangular

% Joint jB, index 2 :
L(2, 2) = sqrt(L(2, 2));
L(2, 1) = L(2, 1) / L(2, 2);
L(1, 1) = L(1, 1) - L(2, 1) * L(2, 1);

% Joint jA, index 1 :
L(1, 1) = sqrt(L(1, 1));


% Inverse of L
Linv(1, 1) = 1 / L(1, 1);
Linv(2, 2) = 1 / L(2, 2);
Linv(2, 1) = - Linv(1, 1) * ((Linv(2, 2) * L(2, 1)) + 0);

% Inverse of H
Hinv(1, 1) =  + (Linv(1, 1) * Linv(1, 1));
Hinv(2, 2) =  + (Linv(2, 1) * Linv(2, 1)) + (Linv(2, 2) * Linv(2, 2));
Hinv(2, 1) =  + (Linv(2, 1) * Linv(1, 1));
Hinv(1, 2) = Hinv(2, 1);
