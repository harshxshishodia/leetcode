class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        vector<vector<int>> left(rows, vector<int>(cols));
        vector<vector<int>> right(rows, vector<int>(cols));
        vector<vector<int>> up(rows, vector<int>(cols));
        vector<vector<int>> down(rows, vector<int>(cols));

        for (int row = 0; row < rows; row++) {
            int count = 0;

            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 'W') {
                    count = 0;
                } else {
                    left[row][col] = count;

                    if (grid[row][col] == 'E') {
                        count++;
                    }
                }
            }

            count = 0;

            for (int col = cols - 1; col >= 0; col--) {
                if (grid[row][col] == 'W') {
                    count = 0;
                } else {
                    right[row][col] = count;

                    if (grid[row][col] == 'E') {
                        count++;
                    }
                }
            }
        }

        for (int col = 0; col < cols; col++) {
            int count = 0;

            for (int row = 0; row < rows; row++) {
                if (grid[row][col] == 'W') {
                    count = 0;
                } else {
                    up[row][col] = count;

                    if (grid[row][col] == 'E') {
                        count++;
                    }
                }
            }

            count = 0;

            for (int row = rows - 1; row >= 0; row--) {
                if (grid[row][col] == 'W') {
                    count = 0;
                } else {
                    down[row][col] = count;

                    if (grid[row][col] == 'E') {
                        count++;
                    }
                }
            }
        }

        int answer = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '0') {
                    answer = max(
                        answer,
                        left[row][col] +
                        right[row][col] +
                        up[row][col] +
                        down[row][col]
                    );
                }
            }
        }

        return answer;
    }
};
