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

        vector<int> previous(
            cols,
            INF
        );

        int answer =
            numeric_limits<int>::min();

        for (int row = 0;
             row < rows;
             row++) {
            vector<int> current(
                cols,
                INF
            );

            for (int col = 0;
                 col < cols;
                 col++) {
                int best =
                    INF;

                if (row > 0) {
                    best = min(
                        best,
                        previous[col]
                    );
                }

                if (col > 0) {
                    best = min(
                        best,
                        current[col - 1]
                    );
                }

                if (best != INF) {
                    answer = max(
                        answer,
                        grid[row][col] -
                        best
                    );
                }

                current[col] = min(
                    grid[row][col],
                    best
                );
            }

            previous =
                current;
        }

        return answer;
    }
};
