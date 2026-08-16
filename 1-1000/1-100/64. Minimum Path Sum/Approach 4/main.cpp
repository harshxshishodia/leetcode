class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());
        vector<int> dp(cols, 1000000000);
        dp[0] = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int fromTop = dp[col];
                int fromLeft = col > 0 ? dp[col - 1] : 1000000000;

                if (row == 0 && col == 0) {
                    dp[col] = grid[row][col];
                } else {
                    dp[col] = grid[row][col] + min(fromTop, fromLeft);
                }
            }
        }

        return dp[cols - 1];
    }
};
