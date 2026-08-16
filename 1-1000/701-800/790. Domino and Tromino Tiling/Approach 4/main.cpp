class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1000000007;

        if (n == 0) {
            return 1;
        }

        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        vector<long long> dp(
            n + 1
        );

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int width = 3; width <= n; width++) {
            dp[width] = (
                2 * dp[width - 1] +
                dp[width - 3]
            ) % MOD;
        }

        return static_cast<int>(
            dp[n]
        );
    }
};
