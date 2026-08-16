class Solution {
    int solve(const vector<vector<int>>& grid, int row, int col) {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        if (row >= rows || col >= cols || grid[row][col] == 1) {
            return 0;
        }

        if (row == rows - 1 && col == cols - 1) {
            return 1;
        }

        return solve(grid, row + 1, col) +
               solve(grid, row, col + 1);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return solve(obstacleGrid, 0, 0);
    }
};
