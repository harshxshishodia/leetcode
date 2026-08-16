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

        vector<vector<set<int>>> possible(
            rows,
            vector<set<int>>(
                cols
            )
        );

        possible[0][0].insert(
            grid[0][0]
        );

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row == 0 &&
                    col == 0) {
                    continue;
                }

                if (row > 0) {
                    for (int ones :
                         possible[row - 1][col]) {
                        int next =
                            ones +
                            grid[row][col];

                        if (next <= target) {
                            possible[row][col].insert(
                                next
                            );
                        }
                    }
                }

                if (col > 0) {
                    for (int ones :
                         possible[row][col - 1]) {
                        int next =
                            ones +
                            grid[row][col];

                        if (next <= target) {
                            possible[row][col].insert(
                                next
                            );
                        }
                    }
                }
            }
        }

        return
            possible[
                rows - 1
            ][
                cols - 1
            ].count(
                target
            ) >
            0;
    }
};
