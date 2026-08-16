class Solution {
    int solve(
        const vector<vector<int>>& grid,
        int row,
        int col,
        vector<vector<int>>& dp
    ) {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        if (row == rows - 1 && col == cols - 1) {
            return grid[row][col];
        }

        if (row >= rows || col >= cols) {
            return 1000000000;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        dp[row][col] = grid[row][col] + min(
            solve(grid, row + 1, col, dp),
            solve(grid, row, col + 1, dp)
        );

        return dp[row][col];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        return solve(grid, 0, 0, dp);
    }
};
