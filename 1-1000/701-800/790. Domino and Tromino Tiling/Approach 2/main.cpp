class Solution {
    static constexpr int MOD = 1000000007;
    vector<array<long long, 2>> memo;
    vector<array<bool, 2>> visited;

    long long solve(
        int width,
        int state
    ) {
        if (state == 0) {
            if (width == 0) {
                return 1;
            }

            if (width == 1) {
                return 1;
            }
        } else if (width <= 1) {
            return 0;
        }

        if (visited[width][state]) {
            return memo[width][state];
        }

        visited[width][state] = true;

        if (state == 0) {
            memo[width][state] = (
                solve(width - 1, 0) +
                solve(width - 2, 0) +
                2 * solve(width - 1, 1)
            ) % MOD;
        } else {
            memo[width][state] = (
                solve(width - 1, 1) +
                solve(width - 2, 0)
            ) % MOD;
        }

        return memo[width][state];
    }

public:
    int numTilings(int n) {
        memo.assign(
            n + 1,
            {0, 0}
        );

        visited.assign(
            n + 1,
            {false, false}
        );

        return static_cast<int>(
            solve(n, 0)
        );
    }
};
