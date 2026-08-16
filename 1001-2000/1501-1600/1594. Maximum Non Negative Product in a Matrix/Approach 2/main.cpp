class Solution {
    struct Range {
        long long minimum;
        long long maximum;
    };

    vector<vector<Range>> memo;
    vector<vector<bool>> visited;

    Range solve(
        const vector<vector<int>>& grid,
        int row,
        int col
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        if (row == rows - 1 &&
            col == cols - 1) {
            return {
                grid[row][col],
                grid[row][col]
            };
        }

        if (visited[row][col]) {
            return memo[row][col];
        }

        visited[row][col] = true;

        long long minimum =
            numeric_limits<long long>::max();

        long long maximum =
            numeric_limits<long long>::min();

        auto consider = [&](Range next) {
            long long first =
                grid[row][col] *
                next.minimum;

            long long second =
                grid[row][col] *
                next.maximum;

            minimum = min({
                minimum,
                first,
                second
            });

            maximum = max({
                maximum,
                first,
                second
            });
        };

        if (row + 1 < rows) {
            consider(
                solve(
                    grid,
                    row + 1,
                    col
                )
            );
        }

        if (col + 1 < cols) {
            consider(
                solve(
                    grid,
                    row,
                    col + 1
                )
            );
        }

        memo[row][col] = {
            minimum,
            maximum
        };

        return memo[row][col];
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD =
            1000000007;

        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        memo.assign(
            rows,
            vector<Range>(
                cols
            )
        );

        visited.assign(
            rows,
            vector<bool>(
                cols
            )
        );

        Range answer =
            solve(
                grid,
                0,
                0
            );

        if (answer.maximum < 0) {
            return -1;
        }

        return static_cast<int>(
            answer.maximum % MOD
        );
    }
};
