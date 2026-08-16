class Solution {
    static constexpr int MOD = 1000000007;

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

            return (
                solve(width - 1, 0) +
                solve(width - 2, 0) +
                2 * solve(width - 1, 1)
            ) % MOD;
        }

        if (width <= 1) {
            return 0;
        }

        return (
            solve(width - 1, 1) +
            solve(width - 2, 0)
        ) % MOD;
    }

public:
    int numTilings(int n) {
        return static_cast<int>(
            solve(n, 0)
        );
    }
};
