class Solution {
public:
    int countPathsWithXorValue(
        vector<vector<int>>& grid,
        int k
    ) {
        const int MOD =
            1000000007;

        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<array<int, 16>> previous(
            cols
        );

        for (int row = 0;
             row < rows;
             row++) {
            vector<array<int, 16>> current(
                cols
            );

            for (int col = 0;
                 col < cols;
                 col++) {
                if (row == 0 &&
                    col == 0) {
                    current[0][grid[0][0]] =
                        1;

                    continue;
                }

                for (int value = 0;
                     value < 16;
                     value++) {
                    int before =
                        value ^
                        grid[row][col];

                    long long ways = 0;

                    if (row > 0) {
                        ways +=
                            previous[col][before];
                    }

                    if (col > 0) {
                        ways +=
                            current[col - 1][before];
                    }

                    current[col][value] =
                        static_cast<int>(
                            ways %
                            MOD
                        );
                }
            }

            previous.swap(
                current
            );
        }

        return
            previous[cols - 1][k];
    }
};
