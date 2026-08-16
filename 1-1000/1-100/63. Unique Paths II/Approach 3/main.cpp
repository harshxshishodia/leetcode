class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = static_cast<int>(obstacleGrid.size());
        int cols = static_cast<int>(obstacleGrid[0].size());
        vector<vector<int>> dp(rows, vector<int>(cols));

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        dp[0][0] = 1;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (obstacleGrid[row][col] == 1) {
                    dp[row][col] = 0;
                    continue;
                }

                if (row == 0 && col == 0) {
                    continue;
                }

                if (row > 0) {
                    dp[row][col] += dp[row - 1][col];
                }

                if (col > 0) {
                    dp[row][col] += dp[row][col - 1];
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};
