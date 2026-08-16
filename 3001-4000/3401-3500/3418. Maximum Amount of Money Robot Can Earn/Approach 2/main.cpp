class Solution {
    vector<vector<array<int, 3>>> memo;
    vector<vector<array<bool, 3>>> visited;

    int solve(
        const vector<vector<int>>& coins,
        int row,
        int col,
        int used
    ) {
        int rows =
            static_cast<int>(coins.size());

        int cols =
            static_cast<int>(coins[0].size());

        if (row >= rows ||
            col >= cols) {
            return
                numeric_limits<int>::min() /
                4;
        }

        if (
            row == rows - 1 &&
            col == cols - 1
        ) {
            if (
                coins[row][col] < 0 &&
                used < 2
            ) {
                return max(
                    coins[row][col],
                    0
                );
            }

            return coins[row][col];
        }

        if (visited[row][col][used]) {
            return memo[row][col][used];
        }

        visited[row][col][used] =
            true;

        int next =
            max(
                solve(
                    coins,
                    row + 1,
                    col,
                    used
                ),
                solve(
                    coins,
                    row,
                    col + 1,
                    used
                )
            );

        int answer =
            coins[row][col] +
            next;

        if (
            coins[row][col] < 0 &&
            used < 2
        ) {
            int neutralized =
                max(
                    solve(
                        coins,
                        row + 1,
                        col,
                        used + 1
                    ),
                    solve(
                        coins,
                        row,
                        col + 1,
                        used + 1
                    )
                );

            answer = max(
                answer,
                neutralized
            );
        }

        memo[row][col][used] =
            answer;

        return answer;
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int rows =
            static_cast<int>(coins.size());

        int cols =
            static_cast<int>(coins[0].size());

        memo.assign(
            rows,
            vector<array<int, 3>>(
                cols
            )
        );

        visited.assign(
            rows,
            vector<array<bool, 3>>(
                cols
            )
        );

        return solve(
            coins,
            0,
            0,
            0
        );
    }
};
