clc;
clear;

%% Test Script
% A is limited to 8 bits wide, signed, and the magnitudes are confined to a range of (1~1/4).
% Determine the required word length of matrix R elements first by using the trigonometric functions available in Matlab.
% Replace the trigonometric functions with the CORDIC scheme and 
% Determine the required iteration number and the accumulation word length in the shift-and-add operations.
%================================================================
%  Setting word length and fraction length
%================================================================
% For R
% Values needed to be optimized for QR cordic
rx_output.WL = 12;
rx_output.FL = 9;

ry_output.WL = 12;
ry_output.FL = 9;
% x_partial, y_partial.
% The register holding partial product when shifting for each iteration.
rx_partial.WL = 20;
rx_partial.FL = 16;

ry_partial.WL = 20;
ry_partial.FL = 16;

% For Q
% Values needed to be optimized for QR cordic
qx_output.WL = 12;
qx_output.FL = 10;

qy_output.WL = 12;
qy_output.FL = 10;

% x_partial, y_partial.
% The register holding partial product when shifting for each iteration.
% 18 8
% 20 10
qx_partial.WL = 12;
qx_partial.FL = 10;

qy_partial.WL = 12;
qy_partial.FL = 10;

%================================================================
%  The range for matrix A (1~0.25)or(-0.25~-1)
%================================================================
LOWER_BOUND = 0.25;
UPPER_BOUND = 1;
MATRIX_SIZE_ROW = 8;
MATRIX_SIZE_COL = 4;
NUM_OF_MATRIX = 1000;
Matrix = Rand_Mat_Gen([MATRIX_SIZE_ROW MATRIX_SIZE_COL],UPPER_BOUND,LOWER_BOUND,NUM_OF_MATRIX);

niter = 7;
Input_Size = fi([],1,8,6 );
Matrix_i = cast(Matrix,'like',Input_Size);   %(fixed point)作業要求wordlength 8bits
% Data type for R calculation
T = qrDataType('fixed', rx_partial, ry_partial, rx_output, ry_output);
% T = fi([],1,12,9);
% Data type for Q calculation
S = qrDataType('fixed', qx_partial, qy_partial, qx_output, qy_output);
% S = fi([],1,12,9);
Q = zeros([8,8]);
R_S = cast(Matrix,'like',T);
Q_S = cast(Q,'like',S);
R_C = cast(Matrix,'like',T);
Q_C = cast(Q,'like',S);
U = cast(Q,'like',S);

buildInstrumentedMex Standard_QR_Algorithm -args {Matrix_i(:,:,1)} -histogram
buildInstrumentedMex CORDIC_QR_Algorithm -args {Matrix_i(:,:,1), niter} -histogram
%%
%Algorithm
for i = 1:NUM_OF_MATRIX
    R(:,:,i) = qr(Matrix(:,:,i));
    [Q_S(:,:,i), R_S(:,:,i)] = Standard_QR_Algorithm_mex(Matrix_i(:,:,i));         %trigonometric functions
    [Q_C(:,:,i), R_C(:,:,i)] = CORDIC_QR_Algorithm_mex(Matrix_i(:,:,i),niter);     %replace the trigonometric functions with the CORDIC scheme
end
% Verify Result
showInstrumentationResults Standard_QR_Algorithm_mex
showInstrumentationResults CORDIC_QR_Algorithm_mex

for j = 1:NUM_OF_MATRIX
    U(:,:,i) = Q_S(:,:,i)'*Q_S(:,:,i);                  % verify the unitary matrix
    delta1(:,:,i) = Delta(R_S(:,:,i),R_C(:,:,i));       % A矩陣以givensrotation分解之R矩陣 和 B矩陣以cordic分解之R矩陣比較
%     delta2(:,:,i) = Delta(R_A_C(:,:,i),R_C(:,:,i));   % A矩陣以cordic分解之R矩陣 和 B矩陣以cordic分解之R矩陣比較
%                                                       % 若以wordlength=12 delta值皆小於0.01 
end
%% Code generation
codegen Standard_QR_Algorithm -args {Matrix_i(:,:,1)} -config:lib -report
codegen CORDIC_QR_Algorithm -args {Matrix_i,niter(:,:,1)} -config:lib -report