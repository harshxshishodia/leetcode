class NumMatrix {
    vector<vector<int>> matrix;
    vector<vector<int>> blocks;
    int rowBlockSize;
    int colBlockSize;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int rows = matrix.size();
        int cols = matrix[0].size();
        rowBlockSize = sqrt(rows) + 1;
        colBlockSize = sqrt(cols) + 1;
        int rowBlocks = (rows + rowBlockSize - 1) / rowBlockSize;
        int colBlocks = (cols + colBlockSize - 1) / colBlockSize;
        blocks.assign(rowBlocks, vector<int>(colBlocks, 0));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++)
                blocks[row / rowBlockSize][col / colBlockSize] += matrix[row][col];
        }
    }

    void update(int row, int col, int val) {
        blocks[row / rowBlockSize][col / colBlockSize] += val - matrix[row][col];
        matrix[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        int row = row1;

        while (row <= row2) {
            if (row % rowBlockSize == 0 && row + rowBlockSize - 1 <= row2) {
                int col = col1;

                while (col <= col2) {
                    if (col % colBlockSize == 0 && col + colBlockSize - 1 <= col2) {
                        sum += blocks[row / rowBlockSize][col / colBlockSize];
                        col += colBlockSize;
                    } else {
                        for (int currentRow = row; currentRow < row + rowBlockSize; currentRow++)
                            sum += matrix[currentRow][col];

                        col++;
                    }
                }

                row += rowBlockSize;
            } else {
                for (int col = col1; col <= col2; col++)
                    sum += matrix[row][col];

                row++;
            }
        }

        return sum;
    }
};