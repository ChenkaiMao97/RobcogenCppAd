function [Hinv L Linv] = invertJSIM(H)

% The following code computes the lower triangular matrix L such that
%  H = L' L  (LTL factorization)
% Then it computes the inverse of L and the inverse of H

% LTL factorization
L = tril(H); % lower triangular

% Joint jE, index 5 :
L(5, 5) = sqrt(L(5, 5));
L(5, 4) = L(5, 4) / L(5, 5);
L(5, 3) = L(5, 3) / L(5, 5);
L(5, 2) = L(5, 2) / L(5, 5);
L(5, 1) = L(5, 1) / L(5, 5);
L(4, 4) = L(4, 4) - L(5, 4) * L(5, 4);
L(4, 3) = L(4, 3) - L(5, 4) * L(5, 3);
L(4, 2) = L(4, 2) - L(5, 4) * L(5, 2);
L(4, 1) = L(4, 1) - L(5, 4) * L(5, 1);
L(3, 3) = L(3, 3) - L(5, 3) * L(5, 3);
L(3, 2) = L(3, 2) - L(5, 3) * L(5, 2);
L(3, 1) = L(3, 1) - L(5, 3) * L(5, 1);
L(2, 2) = L(2, 2) - L(5, 2) * L(5, 2);
L(2, 1) = L(2, 1) - L(5, 2) * L(5, 1);
L(1, 1) = L(1, 1) - L(5, 1) * L(5, 1);

% Joint jD, index 4 :
L(4, 4) = sqrt(L(4, 4));
L(4, 3) = L(4, 3) / L(4, 4);
L(4, 2) = L(4, 2) / L(4, 4);
L(4, 1) = L(4, 1) / L(4, 4);
L(3, 3) = L(3, 3) - L(4, 3) * L(4, 3);
L(3, 2) = L(3, 2) - L(4, 3) * L(4, 2);
L(3, 1) = L(3, 1) - L(4, 3) * L(4, 1);
L(2, 2) = L(2, 2) - L(4, 2) * L(4, 2);
L(2, 1) = L(2, 1) - L(4, 2) * L(4, 1);
L(1, 1) = L(1, 1) - L(4, 1) * L(4, 1);

% Joint jC, index 3 :
L(3, 3) = sqrt(L(3, 3));
L(3, 2) = L(3, 2) / L(3, 3);
L(3, 1) = L(3, 1) / L(3, 3);
L(2, 2) = L(2, 2) - L(3, 2) * L(3, 2);
L(2, 1) = L(2, 1) - L(3, 2) * L(3, 1);
L(1, 1) = L(1, 1) - L(3, 1) * L(3, 1);

% Joint jB, index 2 :
L(2, 2) = sqrt(L(2, 2));
L(2, 1) = L(2, 1) / L(2, 2);
L(1, 1) = L(1, 1) - L(2, 1) * L(2, 1);

% Joint jA, index 1 :
L(1, 1) = sqrt(L(1, 1));


% Inverse of L
Linv(1, 1) = 1 / L(1, 1);
Linv(2, 2) = 1 / L(2, 2);
Linv(3, 3) = 1 / L(3, 3);
Linv(4, 4) = 1 / L(4, 4);
Linv(5, 5) = 1 / L(5, 5);
Linv(2, 1) = - Linv(1, 1) * ((Linv(2, 2) * L(2, 1)) + 0);
Linv(3, 2) = - Linv(2, 2) * ((Linv(3, 3) * L(3, 2)) + 0);
Linv(3, 1) = - Linv(1, 1) * ((Linv(3, 2) * L(2, 1)) + (Linv(3, 3) * L(3, 1)) + 0);
Linv(4, 3) = - Linv(3, 3) * ((Linv(4, 4) * L(4, 3)) + 0);
Linv(4, 2) = - Linv(2, 2) * ((Linv(4, 3) * L(3, 2)) + (Linv(4, 4) * L(4, 2)) + 0);
Linv(4, 1) = - Linv(1, 1) * ((Linv(4, 2) * L(2, 1)) + (Linv(4, 3) * L(3, 1)) + (Linv(4, 4) * L(4, 1)) + 0);
Linv(5, 4) = - Linv(4, 4) * ((Linv(5, 5) * L(5, 4)) + 0);
Linv(5, 3) = - Linv(3, 3) * ((Linv(5, 4) * L(4, 3)) + (Linv(5, 5) * L(5, 3)) + 0);
Linv(5, 2) = - Linv(2, 2) * ((Linv(5, 3) * L(3, 2)) + (Linv(5, 4) * L(4, 2)) + (Linv(5, 5) * L(5, 2)) + 0);
Linv(5, 1) = - Linv(1, 1) * ((Linv(5, 2) * L(2, 1)) + (Linv(5, 3) * L(3, 1)) + (Linv(5, 4) * L(4, 1)) + (Linv(5, 5) * L(5, 1)) + 0);

% Inverse of H
Hinv(1, 1) =  + (Linv(1, 1) * Linv(1, 1));
Hinv(2, 2) =  + (Linv(2, 1) * Linv(2, 1)) + (Linv(2, 2) * Linv(2, 2));
Hinv(2, 1) =  + (Linv(2, 1) * Linv(1, 1));
Hinv(1, 2) = Hinv(2, 1);
Hinv(3, 3) =  + (Linv(3, 1) * Linv(3, 1)) + (Linv(3, 2) * Linv(3, 2)) + (Linv(3, 3) * Linv(3, 3));
Hinv(3, 2) =  + (Linv(3, 1) * Linv(2, 1)) + (Linv(3, 2) * Linv(2, 2));
Hinv(2, 3) = Hinv(3, 2);
Hinv(3, 1) =  + (Linv(3, 1) * Linv(1, 1));
Hinv(1, 3) = Hinv(3, 1);
Hinv(4, 4) =  + (Linv(4, 1) * Linv(4, 1)) + (Linv(4, 2) * Linv(4, 2)) + (Linv(4, 3) * Linv(4, 3)) + (Linv(4, 4) * Linv(4, 4));
Hinv(4, 3) =  + (Linv(4, 1) * Linv(3, 1)) + (Linv(4, 2) * Linv(3, 2)) + (Linv(4, 3) * Linv(3, 3));
Hinv(3, 4) = Hinv(4, 3);
Hinv(4, 2) =  + (Linv(4, 1) * Linv(2, 1)) + (Linv(4, 2) * Linv(2, 2));
Hinv(2, 4) = Hinv(4, 2);
Hinv(4, 1) =  + (Linv(4, 1) * Linv(1, 1));
Hinv(1, 4) = Hinv(4, 1);
Hinv(5, 5) =  + (Linv(5, 1) * Linv(5, 1)) + (Linv(5, 2) * Linv(5, 2)) + (Linv(5, 3) * Linv(5, 3)) + (Linv(5, 4) * Linv(5, 4)) + (Linv(5, 5) * Linv(5, 5));
Hinv(5, 4) =  + (Linv(5, 1) * Linv(4, 1)) + (Linv(5, 2) * Linv(4, 2)) + (Linv(5, 3) * Linv(4, 3)) + (Linv(5, 4) * Linv(4, 4));
Hinv(4, 5) = Hinv(5, 4);
Hinv(5, 3) =  + (Linv(5, 1) * Linv(3, 1)) + (Linv(5, 2) * Linv(3, 2)) + (Linv(5, 3) * Linv(3, 3));
Hinv(3, 5) = Hinv(5, 3);
Hinv(5, 2) =  + (Linv(5, 1) * Linv(2, 1)) + (Linv(5, 2) * Linv(2, 2));
Hinv(2, 5) = Hinv(5, 2);
Hinv(5, 1) =  + (Linv(5, 1) * Linv(1, 1));
Hinv(1, 5) = Hinv(5, 1);
