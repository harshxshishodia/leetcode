class Solution {
    static constexpr int MOD = 1000000007;

    int solve(
        const vector<vector<int>>& grid,
        int k,
        int row,
        int col,
        int current
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        current ^=
            grid[row][col];

        if (
            row == rows - 1 &&
            col == cols - 1
        ) {
            return current == k;
        }

        long long answer = 0;

        if (row + 1 < rows) {
            answer +=
                solve(
                    grid,
                    k,
                    row + 1,
                    col,
                    current
                );
        }

        if (col + 1 < cols) {
            answer +=
                solve(
                    grid,
                    k,
                    row,
                    col + 1,
                    current
                );
        }

        return static_cast<int>(
            answer %
            MOD
        );
    }

public:
    int countPathsWithXorValue(
        vector<vector<int>>& grid,
        int k
    ) {
        return solve(
            grid,
            k,
            0,
            0,
            0
        );
    }
};
