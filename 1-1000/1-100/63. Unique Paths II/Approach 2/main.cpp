class Solution {
    int solve(
        const vector<vector<int>>& grid,
        int row,
        int col,
        vector<vector<int>>& dp
    ) {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        if (row >= rows || col >= cols || grid[row][col] == 1) {
            return 0;
        }

        if (row == rows - 1 && col == cols - 1) {
            return 1;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        dp[row][col] = solve(grid, row + 1, col, dp) +
                       solve(grid, row, col + 1, dp);

        return dp[row][col];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = static_cast<int>(obstacleGrid.size());
        int cols = static_cast<int>(obstacleGrid[0].size());
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        return solve(obstacleGrid, 0, 0, dp);
    }
};
