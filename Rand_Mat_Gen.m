% For testbench, to generate at least 10 random matrices of size 84 and with a full column rank (4). 
% All magnitudes of all matrix elements should be confined to a range of (1~1/4) and can be either positive or negative. 
% The precision requirement should be met in all cases.
function matrices = Rand_Mat_Gen(matrixSize, maxValue, minValue, matrixCount)

rng(12)
% matrixCount = 10;     % 生成的矩陣數量
% matrixSize = [8, 4];  % 矩陣的大小
% minValue = 1/4;       % 元素的最小值
% maxValue = 1;         % 元素的最大值
% precision = 8;        % 8 bits
matrices = zeros([matrixSize, matrixCount]);  % 儲存生成的矩陣

for i = 1:matrixCount
    while true
        % 生成隨機矩陣，使矩陣內元素落在range(maxValue - minValue)之內
        matrix = (rand(matrixSize) * (maxValue - minValue)) + minValue;
        % 判斷矩陣是否為行滿秩
        if rank(matrix) == matrixSize(2)
%             matrix = fi(matrix, true, precision);
            matrices(:,:,i) = matrix;
            break;
        end
    end
end

% 生成隨機正負號
signs = randi([0, 1], matrixSize) * 2 - 1;
% 隨機分配正負號到矩陣元素
matrices = matrices .* signs;
end  

% precision = 8;  % 8 bits
% 
% % 隨機矩陣
% matrices = cell(matrixCount, 1);
% for i = 1:matrixCount
%     while true
%         % 使矩陣內元素落在range(maxValue - minValue)之內
%         matrix = (rand(matrixSize) * (maxValue - minValue)) + minValue;
%         % 判斷矩陣是否為行滿秩
%         if rank(matrix) == matrixSize(2)
%             % 將矩陣元素的精度限制為8位
%             matrix = fi(matrix, true, precision);
%             matrices{i} = matrix;
%             break;
%         end
%     end
% end
