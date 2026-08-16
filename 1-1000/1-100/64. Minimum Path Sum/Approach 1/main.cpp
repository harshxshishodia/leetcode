class Solution {
    int solve(const vector<vector<int>>& grid, int row, int col) {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        if (row == rows - 1 && col == cols - 1) {
            return grid[row][col];
        }

        if (row >= rows || col >= cols) {
            return 1000000000;
        }

        return grid[row][col] + min(
            solve(grid, row + 1, col),
            solve(grid, row, col + 1)
        );
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        return solve(grid, 0, 0);
    }
};
