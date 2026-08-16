class NumMatrix {
    vector<vector<int>> dp;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        dp.assign(m + 1, vector<int>(n + 1, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                dp[r + 1][c + 1] = matrix[r][c] + dp[r][c + 1] + dp[r + 1][c] - dp[r][c];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};
