class Solution {
public:
    long long maxScore(
        vector<int>& a,
        vector<int>& b
    ) {
        int n =
            static_cast<int>(b.size());

        const long long NEG =
            numeric_limits<long long>::min() /
            4;

        vector<array<long long, 5>> dp(
            n + 1
        );

        for (int picked = 0;
             picked < 4;
             picked++) {
            dp[n][picked] =
                NEG;
        }

        dp[n][4] =
            0;

        for (int index = n - 1;
             index >= 0;
             index--) {
            dp[index][4] =
                0;

            for (int picked = 3;
                 picked >= 0;
                 picked--) {
                long long take =
                    NEG;

                if (dp[index + 1][picked + 1] != NEG) {
                    take =
                        1LL *
                        a[picked] *
                        b[index] +
                        dp[index + 1][picked + 1];
                }

                dp[index][picked] = max(
                    dp[index + 1][picked],
                    take
                );
            }
        }

        return dp[0][0];
    }
};
