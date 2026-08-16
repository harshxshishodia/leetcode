class Solution {
    bool hasPath(
        const vector<vector<int>>& grid
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<vector<bool>> reachable(
            rows,
            vector<bool>(
                cols
            )
        );

        if (grid[0][0] == 0) {
            return false;
        }

        reachable[0][0] = true;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) {
                    continue;
                }

                if (row > 0 &&
                    reachable[row - 1][col]) {
                    reachable[row][col] = true;
                }

                if (col > 0 &&
                    reachable[row][col - 1]) {
                    reachable[row][col] = true;
                }
            }
        }

        return
            reachable[
                rows - 1
            ][
                cols - 1
            ];
    }

public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if (!hasPath(grid)) {
            return true;
        }

        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (
                    (
                        row == 0 &&
                        col == 0
                    ) ||
                    (
                        row == rows - 1 &&
                        col == cols - 1
                    ) ||
                    grid[row][col] == 0
                ) {
                    continue;
                }

                grid[row][col] = 0;

                if (!hasPath(grid)) {
                    grid[row][col] = 1;
                    return true;
                }

                grid[row][col] = 1;
            }
        }

        return false;
    }
};
