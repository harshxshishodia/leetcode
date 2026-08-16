class Solution {
public:
    int countOfArrays(
        int n,
        int m,
        int k
    ) {
        const long long MOD =
            1000000007;

        long long evenChoices =
            m /
            2;

        long long oddChoices =
            m -
            evenChoices;

        vector<array<long long, 2>> dp(
            k + 1
        );

        dp[0][0] =
            oddChoices;

        dp[0][1] =
            evenChoices;

        for (int index = 1;
             index < n;
             index++) {
            vector<array<long long, 2>> next(
                k + 1
            );

            for (int count = 0;
                 count <= k;
                 count++) {
                long long totalPrevious =
                    (
                        dp[count][0] +
                        dp[count][1]
                    ) %
                    MOD;

                next[count][0] =
                    totalPrevious *
                    oddChoices %
                    MOD;

                next[count][1] =
                    dp[count][0] *
                    evenChoices %
                    MOD;

                if (count > 0) {
                    next[count][1] =
                        (
                            next[count][1] +
                            dp[count - 1][1] *
                            evenChoices
                        ) %
                        MOD;
                }
            }

            dp.swap(
                next
            );
        }

        return static_cast<int>(
            (
                dp[k][0] +
                dp[k][1]
            ) %
            MOD
        );
    }
};
