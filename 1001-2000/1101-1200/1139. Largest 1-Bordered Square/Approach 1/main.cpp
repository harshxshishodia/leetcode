class Solution {
    bool valid(
        const vector<vector<int>>& grid,
        int top,
        int left,
        int side
    ) {
        int bottom =
            top + side - 1;

        int right =
            left + side - 1;

        for (int col = left; col <= right; col++) {
            if (grid[top][col] == 0 ||
                grid[bottom][col] == 0) {
                return false;
            }
        }

        for (int row = top; row <= bottom; row++) {
            if (grid[row][left] == 0 ||
                grid[row][right] == 0) {
                return false;
            }
        }

        return true;
    }

public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        int maximumSide =
            min(
                rows,
                cols
            );

        for (int side = maximumSide;
             side >= 1;
             side--) {
            for (int top = 0;
                 top + side <= rows;
                 top++) {
                for (int left = 0;
                     left + side <= cols;
                     left++) {
                    if (valid(
                            grid,
                            top,
                            left,
                            side)) {
                        return side * side;
                    }
                }
            }
        }

        return 0;
    }
};
