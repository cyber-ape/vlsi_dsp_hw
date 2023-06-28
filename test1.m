clc;
clear;

A = Rand_Mat(0.25,1,8,4);
B = fi(A,1,8,5);
C = [];
C(:) = B+B;
C_fi = fi(C,1,8,5);
% function D = Delta(mat1,mat2)
% reg = A-B;
a = sum(sum(C.*C));
b = sum(sum(A.*A));
D = sqrt(a/b);
% end

%testbench 隨機矩陣
function [M] = Rand_Mat(a,b,m,n)
    i=0;
    while i==0                      
        M=a+(b-a).*rand(m,n);       %使矩陣內元素落在range(a,b)之內
        if rank(M) == n             %使矩陣為行滿秩
                i=1;
        end
    end
    for i = 1:m 
        for j = 1:n
            s = randi([0,1]);
            if s == 1
                M(i, j) = -M(i, j); %使矩陣內元素可為正負值
            end
        end
    end
end
