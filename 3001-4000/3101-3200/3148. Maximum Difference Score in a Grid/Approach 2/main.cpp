class Solution {
public:
    int maxScore(
        vector<vector<int>>& grid
    ) {
        int rows =
            static_cast<int>(
                grid.size()
            );

        int cols =
            static_cast<int>(
                grid[0].size()
            );

        const int INF =
            numeric_limits<int>::max();

        vector<vector<int>> minimum(
            rows,
            vector<int>(
                cols,
                INF
            )
        );

        int answer =
            numeric_limits<int>::min();

        for (int row = 0;
             row < rows;
             row++) {
            for (int col = 0;
                 col < cols;
                 col++) {
                int previous =
                    INF;

                if (row > 0) {
                    previous = min(
                        previous,
                        minimum[row - 1][col]
                    );
                }

                if (col > 0) {
                    previous = min(
                        previous,
                        minimum[row][col - 1]
                    );
                }

                if (previous != INF) {
                    answer = max(
                        answer,
                        grid[row][col] -
                        previous
                    );
                }

                minimum[row][col] = min(
                    grid[row][col],
                    previous
                );
            }
        }

        return answer;
    }
};
