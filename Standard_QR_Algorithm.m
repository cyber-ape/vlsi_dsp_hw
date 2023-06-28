% Standard_QR_Algorithm.m
function [Q,R] = Standard_QR_Algorithm(M_in) %#codegen
  [m,n] = size(M_in);
  R = M_in;
  Q = coder.nullcopy(repmat(M_in(:,1),1,m));    % Declare type and size of Q
  Q(:) = eye(m);                                % Initialize Q
  for j=1:n
    for i=m:-1:(j+1)
      [R(j,j:end),R(i,j:end),Q(:,j),Q(:,i)] = ...
          Standard_Givens(R(j,j:end),R(i,j:end),Q(:,j),Q(:,i));
    end
  end
end

% Standard_Givens_Rotation
% The givensrotation function uses division and square root, 
% which are expensive in fixed-point, but good for floating-point algorithms.
function [x,y,u,v] = Standard_Givens(x,y,u,v) %#codegen
  a = x(1); b = y(1);
  if b==0   
    % No rotation necessary.  c = 1; s = 0;
    return;
  else
%     if abs(b) > abs(a)
%       t = a/b; s = 1/sqrt(1+t^2); c = s*t;
%     else
      t = b/a; c = 1/sqrt(1+t^2); s = c*t;
%     end
  end
  x0 = x;             u0 = u;
  % x and y form R,   u and v form Q
  x(:) = c*x0 + s*y;  u(:) = c*u0 + s*v;
  y(:) = -s*x0 + c*y;  v(:) = -s*u0 + c*v;
end