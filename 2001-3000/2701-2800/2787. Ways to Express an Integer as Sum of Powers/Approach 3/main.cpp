class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1000000007;

        vector<int> powers;

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

            powers.push_back(static_cast<int>(value));
        }

        int count = static_cast<int>(powers.size());

        vector<vector<int>> dp(
            count + 1,
            vector<int>(n + 1)
        );

        dp[0][0] = 1;

        for (int index = 1; index <= count; index++) {
            for (int sum = 0; sum <= n; sum++) {
                dp[index][sum] = dp[index - 1][sum];

                if (sum >= powers[index - 1]) {
                    dp[index][sum] =
                        (
                            dp[index][sum] +
                            dp[index - 1][sum - powers[index - 1]]
                        ) %
                        MOD;
                }
            }
        }

        return dp[count][n];
    }
};
