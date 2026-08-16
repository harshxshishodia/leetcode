class Solution {
public:
    int minimumOperations(
        vector<vector<int>>& grid
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        array<int, 10> previous = {};

        for (int digit = 0;
             digit <= 9;
             digit++) {
            for (int row = 0;
                 row < rows;
                 row++) {
                previous[digit] +=
                    grid[row][0] !=
                    digit;
            }
        }

        for (int column = 1;
             column < cols;
             column++) {
            array<int, 10> cost = {};

            for (int digit = 0;
                 digit <= 9;
                 digit++) {
                for (int row = 0;
                     row < rows;
                     row++) {
                    cost[digit] +=
                        grid[row][column] !=
                        digit;
                }
            }

            array<int, 10> current;

            current.fill(
                numeric_limits<int>::max()
            );

            for (int digit = 0;
                 digit <= 9;
                 digit++) {
                for (int old = 0;
                     old <= 9;
                     old++) {
                    if (old == digit) {
                        continue;
                    }

                    current[digit] = min(
                        current[digit],
                        previous[old] +
                        cost[digit]
                    );
                }
            }

            previous =
                current;
        }

        return *min_element(
            previous.begin(),
            previous.end()
        );
    }
};
