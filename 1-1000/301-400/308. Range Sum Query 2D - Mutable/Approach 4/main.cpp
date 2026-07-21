class NumMatrix {
    vector<vector<int>> matrix;
    vector<vector<int>> tree;
    int rows;
    int cols;

    void add(int row, int col, int difference) {
        for (int currentRow = row + 1; currentRow <= rows; currentRow += currentRow & -currentRow) {
            for (int currentCol = col + 1; currentCol <= cols; currentCol += currentCol & -currentCol)
                tree[currentRow][currentCol] += difference;
        }
    }

    int prefixSum(int row, int col) {
        int sum = 0;

        for (int currentRow = row + 1; currentRow > 0; currentRow -= currentRow & -currentRow) {
            for (int currentCol = col + 1; currentCol > 0; currentCol -= currentCol & -currentCol)
                sum += tree[currentRow][currentCol];
        }

        return sum;
    }

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        rows = matrix.size();
        cols = matrix[0].size();
        tree.assign(rows + 1, vector<int>(cols + 1, 0));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++)
                add(row, col, matrix[row][col]);
        }
    }

    void update(int row, int col, int val) {
        int difference = val - matrix[row][col];
        matrix[row][col] = val;
        add(row, col, difference);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixSum(row2, col2) - prefixSum(row1 - 1, col2) - prefixSum(row2, col1 - 1) + prefixSum(row1 - 1, col1 - 1);
    }
};