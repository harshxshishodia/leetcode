class Solution {
public:
    int goodBinaryStrings(
        int minLength,
        int maxLength,
        int oneGroup,
        int zeroGroup
    ) {
        const int MOD =
            1000000007;

        vector<long long> dp(
            maxLength + 1
        );

        dp[0] = 1;

        long long answer = 0;

        for (int length = 1;
             length <= maxLength;
             length++) {
            if (length >= oneGroup) {
                dp[length] +=
                    dp[length - oneGroup];
            }

            if (length >= zeroGroup) {
                dp[length] +=
                    dp[length - zeroGroup];
            }

            dp[length] %=
                MOD;

            if (length >= minLength) {
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
