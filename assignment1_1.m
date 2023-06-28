clc;
clear;

%% Test Script
% A is limited to 8 bits wide, signed, and the magnitudes are confined to a range of (1~1/4).
% Determine the required word length of matrix R elements first by using the trigonometric functions available in Matlab.
% Replace the trigonometric functions with the CORDIC scheme and 
% Determine the required iteration number and the accumulation word length in the shift-and-add operations.
niter = 7;
Input_Size = fi([],1,8,6 );
T = fi([],1,12,9);
S = fi([],1,12,9);
Matrix = Rand_Mat_Gen([8 4],1,1/4,1000);
Q = zeros([8,8]);
Matrix_i = cast(Matrix,'like',Input_Size);   %(fixed point)作業要求wordlength 8bits
R_S = cast(Matrix,'like',T);
Q_S = cast(Q,'like',S);
R_C = cast(Matrix,'like',T);
Q_C = cast(Q,'like',S);
U = cast(Q,'like',S);

buildInstrumentedMex Standard_QR_Algorithm -args {Matrix_i(:,:,1)} -histogram
buildInstrumentedMex CORDIC_QR_Algorithm -args {Matrix_i(:,:,1), niter} -histogram
%%
%Algorithm
for i = 1:1000
    R(:,:,i) = qr(Matrix(:,:,i));
    [Q_S(:,:,i), R_S(:,:,i)] = Standard_QR_Algorithm_mex(Matrix_i(:,:,i));         %trigonometric functions
    [Q_C(:,:,i), R_C(:,:,i)] = CORDIC_QR_Algorithm_mex(Matrix_i(:,:,i),niter);     %replace the trigonometric functions with the CORDIC scheme
end
% Verify Result
showInstrumentationResults Standard_QR_Algorithm_mex
showInstrumentationResults CORDIC_QR_Algorithm_mex

for j = 1:1000
    U(:,:,i) = Q_S(:,:,i)'*Q_S(:,:,i);                  % verify the unitary matrix
    delta1(:,:,i) = Delta(R_S(:,:,i),R_C(:,:,i));       % A矩陣以givensrotation分解之R矩陣 和 B矩陣以cordic分解之R矩陣比較
%     delta2(:,:,i) = Delta(R_A_C(:,:,i),R_C(:,:,i));   % A矩陣以cordic分解之R矩陣 和 B矩陣以cordic分解之R矩陣比較
%                                                       % 若以wordlength=12 delta值皆小於0.01 
end
%% Code generation
codegen Standard_QR_Algorithm -args {Matrix_i(:,:,1)} -config:lib -report
codegen CORDIC_QR_Algorithm -args {Matrix_i,niter(:,:,1)} -config:lib -report