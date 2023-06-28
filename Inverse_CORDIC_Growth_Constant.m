% Inverse_CORDIC_Growth_Constant
% This function returns the inverse of the CORDIC growth factor after niter iterations.
function Kn = Inverse_CORDIC_Growth_Constant(niter)
  Kn = 1/prod(sqrt(1+2.^(-2*(0:double(niter)-1))));
end