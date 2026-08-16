class Solution {
    vector<vector<vector<int>>> memo;
    int target;

    int solve(
        const vector<vector<int>>& grid,
        int row,
        int col,
        int ones
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
            return 0;
        }

        if (row == rows - 1 &&
            col == cols - 1) {
            return
                ones ==
                target;
        }

        if (memo[row][col][ones] != -1) {
            return memo[row][col][ones];
        }

        bool answer = false;

        if (row + 1 < rows) {
            answer =
                solve(
                    grid,
                    row + 1,
                    col,
                    ones
                );
        }

        if (!answer &&
            col + 1 < cols) {
            answer =
                solve(
                    grid,
                    row,
                    col + 1,
                    ones
                );
        }

        memo[row][col][ones] =
            answer;

        return memo[row][col][ones];
    }

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

        target =
            cells /
            2;

        memo.assign(
            rows,
            vector<vector<int>>(
                cols,
                vector<int>(
                    target + 1,
                    -1
                )
            )
        );

        return solve(
            grid,
            0,
            0,
            0
        );
    }
};
