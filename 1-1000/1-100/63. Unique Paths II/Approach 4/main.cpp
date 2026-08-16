class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = static_cast<int>(obstacleGrid.size());
        int cols = static_cast<int>(obstacleGrid[0].size());
        vector<int> dp(cols);
        dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (obstacleGrid[row][col] == 1) {
                    dp[col] = 0;
                } else if (col > 0) {
                    dp[col] += dp[col - 1];
                }
            }
        }

        return dp[cols - 1];
    }
};
