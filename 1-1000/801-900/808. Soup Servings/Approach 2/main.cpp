class Solution {
    vector<vector<double>> memo;
    vector<vector<bool>> visited;

    double solve(
        int a,
        int b
    ) {
        if (a <= 0 &&
            b <= 0) {
            return 0.5;
        }

        if (a <= 0) {
            return 1.0;
        }

        if (b <= 0) {
            return 0.0;
        }

        if (visited[a][b]) {
            return memo[a][b];
        }

        visited[a][b] = true;

        memo[a][b] =
            0.25 * (
                solve(
                    max(0, a - 4),
                    b
                ) +
                solve(
                    max(0, a - 3),
                    max(0, b - 1)
                ) +
                solve(
                    max(0, a - 2),
                    max(0, b - 2)
                ) +
                solve(
                    max(0, a - 1),
                    max(0, b - 3)
                )
            );

        return memo[a][b];
    }

public:
    double soupServings(int n) {
        int units =
            (n + 24) /
            25;

        memo.assign(
            units + 1,
            vector<double>(
                units + 1
            )
        );

        visited.assign(
            units + 1,
            vector<bool>(
                units + 1
            )
        );

        return solve(
            units,
            units
        );
    }
};
