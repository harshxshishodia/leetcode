class NumMatrix {
    vector<vector<int>> rowPrefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        rowPrefix.assign(m, vector<int>(n + 1, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                rowPrefix[r][c + 1] = rowPrefix[r][c] + matrix[r][c];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int totalSum = 0;
        for (int r = row1; r <= row2; r++) {
            totalSum += rowPrefix[r][col2 + 1] - rowPrefix[r][col1];
        }
        return totalSum;
    }
};
