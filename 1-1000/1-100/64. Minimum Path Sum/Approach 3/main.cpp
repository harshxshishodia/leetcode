class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());
        vector<vector<int>> dp(rows, vector<int>(cols));

        dp[0][0] = grid[0][0];

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row == 0 && col == 0) {
                    continue;
                }

                int fromTop = row > 0 ? dp[row - 1][col] : 1000000000;
                int fromLeft = col > 0 ? dp[row][col - 1] : 1000000000;
                dp[row][col] = grid[row][col] + min(fromTop, fromLeft);
            }
        }

        return dp[rows - 1][cols - 1];
    }
};
