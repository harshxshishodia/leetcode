class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD =
            1000000007;

        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(
                k + 1
            )
        );

        vector<vector<long long>> prefix(
            n + 1,
            vector<long long>(
                k + 1
            )
        );

        for (int points = 0;
             points <= n;
             points++) {
            dp[points][0] = 1;
        }

        for (int points = 1;
             points <= n;
             points++) {
            prefix[points][0] =
                (
                    prefix[points - 1][0] +
                    dp[points][0]
                ) %
                MOD;
        }

        for (int points = 1;
             points <= n;
             points++) {
            for (int segments = 1;
                 segments <= k;
                 segments++) {
                dp[points][segments] =
                    dp[points - 1][segments];

                dp[points][segments] +=
                    prefix[points - 1][segments - 1];

                dp[points][segments] %=
                    MOD;

                prefix[points][segments] =
                    (
                        prefix[points - 1][segments] +
                        dp[points][segments]
                    ) %
                    MOD;
            }
        }

        return static_cast<int>(
            dp[n][k]
        );
    }
};
