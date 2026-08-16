class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1000000007;

        vector<int> dp(n + 1);
        dp[0] = 1;

        for (int base = 1; ; base++) {
            long long value = 1;

            for (int exponent = 0; exponent < x; exponent++) {
                value *= base;

                if (value > n) {
                    break;
                }
            }

            if (value > n) {
                break;
            }

            int power = static_cast<int>(value);

            for (int sum = n; sum >= power; sum--) {
                dp[sum] =
                    (
                        dp[sum] +
                        dp[sum - power]
                    ) %
                    MOD;
            }
        }

        return dp[n];
    }
};
