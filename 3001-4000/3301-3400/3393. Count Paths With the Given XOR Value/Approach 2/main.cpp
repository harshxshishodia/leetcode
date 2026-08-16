class Solution {
    static constexpr int MOD = 1000000007;

    vector<vector<array<int, 16>>> memo;
    vector<vector<array<bool, 16>>> visited;

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

        if (visited[row][col][current]) {
            return memo[row][col][current];
        }

        visited[row][col][current] =
            true;

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

        memo[row][col][current] =
            static_cast<int>(
                answer %
                MOD
            );

        return memo[row][col][current];
    }

public:
    int countPathsWithXorValue(
        vector<vector<int>>& grid,
        int k
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        memo.assign(
            rows,
            vector<array<int, 16>>(
                cols
            )
        );

        visited.assign(
            rows,
            vector<array<bool, 16>>(
                cols
            )
        );

        return solve(
            grid,
            k,
            0,
            0,
            0
        );
    }
};
