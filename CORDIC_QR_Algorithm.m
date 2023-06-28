% CORDIC_QR_Algorithm.m
% This pattern of assignment is one key enabler of data-type independent code.
function [Q,R] = CORDIC_QR_Algorithm(M_in,niter) %#codegen
%   Kn = Inverse_CORDIC_Growth_Constant(niter);
  [m,n] = size(M_in);
  Kn = 0.60725334371201;
  R = M_in;
  Q = coder.nullcopy(repmat(M_in(:,1),1,m)); % Declare type and size of Q
  Q(:) = eye(m);                          % Initialize Q
  for j=1:n
    for i=m:-1:(j+1)
      [R(j,j:end),R(i,j:end),Q(:,j),Q(:,i)] = ...
          CORDIC_Givens(R(j,j:end),R(i,j:end),Q(:,j),Q(:,i),niter,Kn);
    end
  end
end

% CORDIC_Givens_Rotation.m
% The heart of this function is applying orthogonal Givens rotations 
% in-place to the rows of R to zero out sub-diagonal elements, 
% thus forming an upper-triangular matrix. 
function [x,y,u,v] = CORDIC_Givens(x,y,u,v,niter,Kn) %#codegen
  if x(1)<0
    % Compensation for 3rd and 4th quadrants
    x(:) = -x;  u(:) = -u;
    y(:) = -y;  v(:) = -v;
  end
  for i=0:niter-1
    x0 = x;
    u0 = u;
    if y(1)<0
      % Counter-clockwise rotation
      % x and y form R,         u and v form Q
      x(:) = x - bitsra(y, i);  u(:) = u - bitsra(v, i);
      y(:) = y + bitsra(x0,i);  v(:) = v + bitsra(u0,i);
    else
      % Clockwise rotation
      % x and y form R,         u and v form Q
      x(:) = x + bitsra(y, i);  u(:) = u + bitsra(v, i);
      y(:) = y - bitsra(x0,i);  v(:) = v - bitsra(u0,i);
    end
  end
  % Set y(1) to exactly zero so R will be upper triangular without round off
  % showing up in the lower triangle.
  y(1) = 0;
  % Normalize the CORDIC gain
  x(:) = Kn * x;  u(:) = Kn * u;
  y(:) = Kn * y;  v(:) = Kn * v;
end