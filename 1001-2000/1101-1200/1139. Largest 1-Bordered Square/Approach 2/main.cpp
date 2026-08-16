class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<vector<int>> rowPrefix(
            rows,
            vector<int>(
                cols + 1
            )
        );

        vector<vector<int>> colPrefix(
            rows + 1,
            vector<int>(
                cols
            )
        );

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                rowPrefix[row][col + 1] =
                    rowPrefix[row][col] +
                    grid[row][col];

                colPrefix[row + 1][col] =
                    colPrefix[row][col] +
                    grid[row][col];
            }
        }

        for (int side = min(rows, cols);
             side >= 1;
             side--) {
            for (int top = 0;
                 top + side <= rows;
                 top++) {
                int bottom =
                    top + side - 1;

                for (int left = 0;
                     left + side <= cols;
                     left++) {
                    int right =
                        left + side - 1;

                    int topCount =
                        rowPrefix[top][right + 1] -
                        rowPrefix[top][left];

                    int bottomCount =
                        rowPrefix[bottom][right + 1] -
                        rowPrefix[bottom][left];

                    int leftCount =
                        colPrefix[bottom + 1][left] -
                        colPrefix[top][left];

                    int rightCount =
                        colPrefix[bottom + 1][right] -
                        colPrefix[top][right];

                    if (topCount == side &&
                        bottomCount == side &&
                        leftCount == side &&
                        rightCount == side) {
                        return side * side;
                    }
                }
            }
        }

        return 0;
    }
};
