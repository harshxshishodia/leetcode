class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row == 0 && col == 0) {
                    continue;
                }

                int fromTop = row > 0 ? grid[row - 1][col] : 1000000000;
                int fromLeft = col > 0 ? grid[row][col - 1] : 1000000000;
                grid[row][col] += min(fromTop, fromLeft);
            }
        }

        return grid[rows - 1][cols - 1];
    }
};
