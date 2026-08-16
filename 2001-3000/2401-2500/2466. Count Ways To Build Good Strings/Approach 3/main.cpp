class Solution {
public:
    int countGoodStrings(
        int low,
        int high,
        int zero,
        int one
    ) {
        const int MOD =
            1000000007;

        vector<long long> dp(
            high + 1
        );

        dp[0] = 1;

        long long answer = 0;

        for (int length = 1;
             length <= high;
             length++) {
            if (length >= zero) {
                dp[length] +=
                    dp[length - zero];
            }

            if (length >= one) {
                dp[length] +=
                    dp[length - one];
            }

            dp[length] %=
                MOD;

            if (length >= low) {
                answer +=
                    dp[length];

                answer %=
                    MOD;
            }
        }

        return static_cast<int>(
            answer
        );
    }
};
