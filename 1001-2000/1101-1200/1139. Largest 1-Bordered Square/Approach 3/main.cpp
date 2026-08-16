class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<vector<int>> horizontal(
            rows,
            vector<int>(cols)
        );

        vector<vector<int>> vertical(
            rows,
            vector<int>(cols)
        );

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) {
                    continue;
                }

                horizontal[row][col] =
                    1 +
                    (
                        col > 0
                            ? horizontal[row][col - 1]
                            : 0
                    );

                vertical[row][col] =
                    1 +
                    (
                        row > 0
                            ? vertical[row - 1][col]
                            : 0
                    );
            }
        }

        int best = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int side = min(
                    horizontal[row][col],
                    vertical[row][col]
                );

                while (side > best) {
                    int top =
                        row - side + 1;

                    int left =
                        col - side + 1;

                    if (horizontal[top][col] >= side &&
                        vertical[row][left] >= side) {
                        best = side;
                        break;
                    }

                    side--;
                }
            }
        }

        return best * best;
    }
};
