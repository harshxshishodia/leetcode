class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = static_cast<int>(obstacleGrid.size());
        int cols = static_cast<int>(obstacleGrid[0].size());

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        obstacleGrid[0][0] = 1;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row == 0 && col == 0) {
                    continue;
                }

                if (obstacleGrid[row][col] == 1) {
                    obstacleGrid[row][col] = 0;
                    continue;
                }

                int fromTop = row > 0 ? obstacleGrid[row - 1][col] : 0;
                int fromLeft = col > 0 ? obstacleGrid[row][col - 1] : 0;
                obstacleGrid[row][col] = fromTop + fromLeft;
            }
        }

        return obstacleGrid[rows - 1][cols - 1];
    }
};
