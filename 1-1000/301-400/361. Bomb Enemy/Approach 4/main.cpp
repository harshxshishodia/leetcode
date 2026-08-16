class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());
        vector<int> columnEnemies(cols);
        int rowEnemies = 0;
        int answer = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (col == 0 || grid[row][col - 1] == 'W') {
                    rowEnemies = 0;

                    for (int c = col; c < cols && grid[row][c] != 'W'; c++) {
                        if (grid[row][c] == 'E') {
                            rowEnemies++;
                        }
                    }
                }

                if (row == 0 || grid[row - 1][col] == 'W') {
                    columnEnemies[col] = 0;

                    for (int r = row; r < rows && grid[r][col] != 'W'; r++) {
                        if (grid[r][col] == 'E') {
                            columnEnemies[col]++;
                        }
                    }
                }

                if (grid[row][col] == '0') {
                    answer = max(
                        answer,
                        rowEnemies + columnEnemies[col]
                    );
                }
            }
        }

        return answer;
    }
};
