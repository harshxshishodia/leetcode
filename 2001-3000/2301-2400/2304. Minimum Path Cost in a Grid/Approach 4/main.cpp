class Solution {
public:
    int minPathCost(
        vector<vector<int>>& grid,
        vector<vector<int>>& moveCost
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<int> previous(
            cols
        );

        for (int col = 0; col < cols; col++) {
            previous[col] =
                grid[0][col];
        }

        for (int row = 0; row + 1 < rows; row++) {
            vector<int> current(
                cols,
                numeric_limits<int>::max()
            );

            for (int col = 0; col < cols; col++) {
                for (int nextCol = 0;
                     nextCol < cols;
                     nextCol++) {
                    current[nextCol] = min(
                        current[nextCol],
                        previous[col] +
                        moveCost[
                            grid[row][col]
                        ][nextCol] +
                        grid[row + 1][nextCol]
                    );
                }
            }

            previous = current;
        }

        return *min_element(
            previous.begin(),
            previous.end()
        );
    }
};
