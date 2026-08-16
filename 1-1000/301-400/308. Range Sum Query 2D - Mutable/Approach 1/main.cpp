class NumMatrix {
    vector<vector<int>> matrix;
    vector<vector<int>> rowPrefixSums;
    int m, n;

public:
    NumMatrix(vector<vector<int>>& mat) : matrix(mat), m(static_cast<int>(mat.size())), n(static_cast<int>(mat[0].size())) {
        rowPrefixSums.assign(m, vector<int>(n + 1, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                rowPrefixSums[r][c + 1] = rowPrefixSums[r][c] + mat[r][c];
            }
        }
    }

    void update(int row, int col, int val) {
        matrix[row][col] = val;
        for (int c = col; c < n; c++) {
            rowPrefixSums[row][c + 1] = rowPrefixSums[row][c] + matrix[row][c];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int r = row1; r <= row2; r++) {
            sum += rowPrefixSums[r][col2 + 1] - rowPrefixSums[r][col1];
        }
        return sum;
    }
};
