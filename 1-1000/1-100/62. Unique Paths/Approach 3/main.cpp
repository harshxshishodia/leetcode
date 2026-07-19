class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int row = 1; row < m; row++) {
            for (int column = 1; column < n; column++)
                dp[row][column] = dp[row - 1][column] + dp[row][column - 1];
        }

        return dp[m - 1][n - 1];
    }
};