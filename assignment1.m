clc;
clear;

niter = 7;
A = Rand_Mat_Gen([8 4],1,1/4,10);
% A = Rand_Mat(0.25,1,8,4);         %(floating point)
B = fi(A,1,8,5);                    %(fixed point)作業要求wordlength 8bits,但delta值表現不佳
C = fi(A,1,12,9);                   %(fixed point)
for i = 1:10
    R(:,:,i) = qr(A(:,:,i));
    [Q_A_S(:,:,i), R_A_S(:,:,i)]  = Standard_QR_Algorithm(A(:,:,i));      %trigonometric functions
    [Q_A_C(:,:,i), R_A_C(:,:,i)]  = CORDIC_QR_Algorithm(A(:,:,i),niter);  %replace the trigonometric functions with the CORDIC scheme
    [Q_B_C(:,:,i), R_B_C(:,:,i)]  = CORDIC_QR_Algorithm(B(:,:,i),niter);  %replace the trigonometric functions with the CORDIC scheme
    [Q_C_C(:,:,i), R_C_C(:,:,i)]  = CORDIC_QR_Algorithm(C(:,:,i),niter);  %replace the trigonometric functions with the CORDIC scheme
    U(:,:,i) = Q_A_S(:,:,i)'*Q_A_S(:,:,i);              % verify the unitary matrix
    delta1(:,:,i) = Delta(R_A_S(:,:,i),R_B_C(:,:,i));   % A矩陣以givensrotation分解之R矩陣 和 B矩陣以cordic分解之R矩陣比較
    delta2(:,:,i) = Delta(R_A_C(:,:,i),R_B_C(:,:,i));   % A矩陣以cordic分解之R矩陣 和 B矩陣以cordic分解之R矩陣比較
    delta3(:,:,i) = Delta(R_A_S(:,:,i),R_C_C(:,:,i));   % A矩陣以givensrotation分解之R矩陣 和 C矩陣以cordic分解之R矩陣比較
    delta4(:,:,i) = Delta(R_A_C(:,:,i),R_C_C(:,:,i));   % A矩陣以cordic分解之R矩陣 和 C矩陣以cordic分解之R矩陣比較
                                                        %若以wordlength=12 delta值皆小於0.01
end