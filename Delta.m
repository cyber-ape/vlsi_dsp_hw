% Quantization_Error_Value_Delta_function
function delta_ = Delta(mat1,mat2,delta) %#codegen
    %Check if meets the criteria delta
    m_dif = (mat1-mat2).^2;
    M = mat1.^2;
    delta_ = sqrt(sum(m_dif(:)))/sqrt(sum(M(:)));
    
%     if delta_ > delta
%         constraint_mex = 0;
%     else
%         constraint_mex = 1;
%     end
end