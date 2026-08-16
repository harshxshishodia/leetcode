class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());
        int answer = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] != '0') {
                    continue;
                }

                int enemies = 0;

                for (int r = row - 1; r >= 0 && grid[r][col] != 'W'; r--) {
                    if (grid[r][col] == 'E') {
                        enemies++;
                    }
                }

                for (int r = row + 1; r < rows && grid[r][col] != 'W'; r++) {
                    if (grid[r][col] == 'E') {
                        enemies++;
                    }
                }

                for (int c = col - 1; c >= 0 && grid[row][c] != 'W'; c--) {
                    if (grid[row][c] == 'E') {
                        enemies++;
                    }
                }

                for (int c = col + 1; c < cols && grid[row][c] != 'W'; c++) {
                    if (grid[row][c] == 'E') {
                        enemies++;
                    }
                }

                answer = max(answer, enemies);
            }
        }

        return answer;
    }
};
