%================================================================
%  Products of 12 successive K multiplications
%================================================================
alpha = [45, 26.565, 14.0362, 7.12502, 3.57633, 1.78991, 0.895174, 0.447614, 0.223811, 0.111906, 0.055953, 0.027977];
alpha = deg2rad(alpha);
K = cos(alpha);

K_12 = 1;
for i = 1 : length(alpha)
     K_12 = K(i) * K_12;
end
K_12;