class Solution {
public:
    int orderOfLargestPlusSign(
        int n,
        vector<vector<int>>& mines
    ) {
        vector<vector<int>> grid(
            n,
            vector<int>(n, 1)
        );

        for (const vector<int>& mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }

        vector<vector<int>> left(
            n,
            vector<int>(n)
        );

        vector<vector<int>> right(
            n,
            vector<int>(n)
        );

        vector<vector<int>> up(
            n,
            vector<int>(n)
        );

        vector<vector<int>> down(
            n,
            vector<int>(n)
        );

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    left[row][col] =
                        1 +
                        (col > 0
                            ? left[row][col - 1]
                            : 0);

                    up[row][col] =
                        1 +
                        (row > 0
                            ? up[row - 1][col]
                            : 0);
                }
            }
        }

        for (int row = n - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {
                if (grid[row][col] == 1) {
                    right[row][col] =
                        1 +
                        (col + 1 < n
                            ? right[row][col + 1]
                            : 0);

                    down[row][col] =
                        1 +
                        (row + 1 < n
                            ? down[row + 1][col]
                            : 0);
                }
            }
        }

        int answer = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                answer = max(
                    answer,
                    min({
                        left[row][col],
                        right[row][col],
                        up[row][col],
                        down[row][col]
                    })
                );
            }
        }

        return answer;
    }
};
