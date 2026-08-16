class Solution {
public:
    int minPathCost(
        vector<vector<int>>& grid,
        vector<vector<int>>& moveCost
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<vector<int>> dp(
            rows,
            vector<int>(
                cols,
                numeric_limits<int>::max()
            )
        );

        for (int col = 0; col < cols; col++) {
            dp[0][col] =
                grid[0][col];
        }

        for (int row = 0; row + 1 < rows; row++) {
            for (int col = 0; col < cols; col++) {
                for (int nextCol = 0;
                     nextCol < cols;
                     nextCol++) {
                    dp[row + 1][nextCol] = min(
                        dp[row + 1][nextCol],
                        dp[row][col] +
                        moveCost[
                            grid[row][col]
                        ][nextCol] +
                        grid[row + 1][nextCol]
                    );
                }
            }
        }

        return *min_element(
            dp[rows - 1].begin(),
            dp[rows - 1].end()
        );
    }
};
