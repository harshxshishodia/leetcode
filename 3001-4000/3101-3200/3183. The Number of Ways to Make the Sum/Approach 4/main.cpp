class Solution {
public:
    int numberOfWays(int n) {
        const int MOD =
            1000000007;

        vector<int> dp(
            n + 1
        );

        dp[0] =
            1;

        for (int coin :
             {1, 2, 6}) {
            for (int sum = coin;
                 sum <= n;
                 sum++) {
                dp[sum] =
                    (
                        dp[sum] +
                        dp[sum - coin]
                    ) %
                        MOD;
            }
        }

        long long answer =
            dp[n];

        if (n >= 4) {
            answer +=
                dp[n - 4];
        }

        if (n >= 8) {
            answer +=
                dp[n - 8];
        }

        return static_cast<int>(
            answer %
            MOD
        );
    }
};
