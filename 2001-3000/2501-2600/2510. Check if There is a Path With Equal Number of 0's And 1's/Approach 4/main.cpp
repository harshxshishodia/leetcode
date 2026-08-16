class Solution {
public:
    bool isThereAPath(vector<vector<int>>& grid) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        int cells =
            rows +
            cols -
            1;

        if (cells % 2 != 0) {
            return false;
        }

        int target =
            cells /
            2;

        const int INF =
            1000000000;

        vector<vector<int>> minimum(
            rows,
            vector<int>(
                cols,
                INF
            )
        );

        vector<vector<int>> maximum(
            rows,
            vector<int>(
                cols,
                -INF
            )
        );

        minimum[0][0] =
            maximum[0][0] =
            grid[0][0];

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row == 0 &&
                    col == 0) {
                    continue;
                }

                if (row > 0) {
                    minimum[row][col] = min(
                        minimum[row][col],
                        minimum[row - 1][col] +
                        grid[row][col]
                    );

                    maximum[row][col] = max(
                        maximum[row][col],
                        maximum[row - 1][col] +
                        grid[row][col]
                    );
                }

                if (col > 0) {
                    minimum[row][col] = min(
                        minimum[row][col],
                        minimum[row][col - 1] +
                        grid[row][col]
                    );

                    maximum[row][col] = max(
                        maximum[row][col],
                        maximum[row][col - 1] +
                        grid[row][col]
                    );
                }
            }
        }

        return
            minimum[
                rows - 1
            ][
                cols - 1
            ] <=
            target &&
            target <=
            maximum[
                rows - 1
            ][
                cols - 1
            ];
    }
};
