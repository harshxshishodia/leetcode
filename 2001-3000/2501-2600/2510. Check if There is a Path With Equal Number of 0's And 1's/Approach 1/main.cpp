class Solution {
    bool solve(
        const vector<vector<int>>& grid,
        int row,
        int col,
        int ones,
        int target
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        ones +=
            grid[row][col];

        int visitedCells =
            row +
            col +
            1;

        int zeroes =
            visitedCells -
            ones;

        if (ones > target ||
            zeroes > target) {
            return false;
        }

        if (row == rows - 1 &&
            col == cols - 1) {
            return
                ones ==
                target;
        }

        if (row + 1 < rows &&
            solve(
                grid,
                row + 1,
                col,
                ones,
                target
            )) {
            return true;
        }

        if (col + 1 < cols &&
            solve(
                grid,
                row,
                col + 1,
                ones,
                target
            )) {
            return true;
        }

        return false;
    }

public:
    bool isThereAPath(vector<vector<int>>& grid) {
        int cells =
            static_cast<int>(grid.size()) +
            static_cast<int>(grid[0].size()) -
            1;

        if (cells % 2 != 0) {
            return false;
        }

        return solve(
            grid,
            0,
            0,
            0,
            cells / 2
        );
    }
};
