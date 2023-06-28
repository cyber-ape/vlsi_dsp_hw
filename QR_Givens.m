%QR_Givens.m (floating point only)
% Same as Standard_QR_Algorithm. 
% It's a trigonometric function.
function [Q,R] = QR_Givens(A)
    [m,n] = size(A);
    R = A;                  %Start with R=A
    Q = eye(m);             %Set Q as the identity matrix    
    for j = 1:n
        for i = m:-1:(j+1)  
            G = eye(m);
            [c,s] = Givens_Rotation( R(i-1,j),R(i,j) );
            G([i-1, i],[i-1, i]) = [c s;-s c];  %三角函數旋轉矩陣
            R = G'*R;
            Q = Q*G;
        end
    end
end 
%Givens_Rotation.m (floating point only)
function [c,s] = Givens_Rotation(a,b)
    if b == 0
        c = 1;
        s = 0;
    else
%         if abs(b) > abs(a)
%             r = a/b;
%             s = 1/ sqrt(1+r^2);
%             c = s*r;
%         else
            t = b/a;
            c = 1/sqrt(1+t^2);
            s = c*t;
%         end
    end
end