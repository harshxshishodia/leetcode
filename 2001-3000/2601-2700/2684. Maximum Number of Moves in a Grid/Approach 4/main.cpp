class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<int> previous(
            rows,
            1
        );

        for (int col = 1;
             col < cols;
             col++) {
            vector<int> current(
                rows
            );

            bool any =
                false;

            for (int row = 0;
                 row < rows;
                 row++) {
                if (!previous[row]) {
                    continue;
                }

                for (int nextRow =
                         max(
                             0,
                             row - 1
                         );
                     nextRow <=
                         min(
                             rows - 1,
                             row + 1
                         );
                     nextRow++) {
                    if (grid[nextRow][col] >
                        grid[row][col - 1]) {
                        current[nextRow] = 1;
                        any = true;
                    }
                }
            }

            if (!any) {
                return col - 1;
            }

            previous =
                current;
        }

        return cols - 1;
    }
};
