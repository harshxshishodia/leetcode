class Solution {
    int solve(int row, int col, int rows, int cols, vector<vector<int>>& dp) {
        if (row == rows - 1 && col == cols - 1) {
            return 1;
        }

        if (row >= rows || col >= cols) {
            return 0;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        dp[row][col] = solve(row + 1, col, rows, cols, dp) +
                       solve(row, col + 1, rows, cols, dp);

        return dp[row][col];
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};
