class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());
        vector<vector<int>> kills(rows, vector<int>(cols));

        for (int row = 0; row < rows; row++) {
            int start = 0;

            while (start < cols) {
                int end = start;
                int enemies = 0;

                while (end < cols && grid[row][end] != 'W') {
                    if (grid[row][end] == 'E') {
                        enemies++;
                    }

                    end++;
                }

                for (int col = start; col < end; col++) {
                    if (grid[row][col] == '0') {
                        kills[row][col] += enemies;
                    }
                }

                start = end + 1;
            }
        }

        for (int col = 0; col < cols; col++) {
            int start = 0;

            while (start < rows) {
                int end = start;
                int enemies = 0;

                while (end < rows && grid[end][col] != 'W') {
                    if (grid[end][col] == 'E') {
                        enemies++;
                    }

                    end++;
                }

                for (int row = start; row < end; row++) {
                    if (grid[row][col] == '0') {
                        kills[row][col] += enemies;
                    }
                }

                start = end + 1;
            }
        }

        int answer = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                answer = max(answer, kills[row][col]);
            }
        }

        return answer;
    }
};
