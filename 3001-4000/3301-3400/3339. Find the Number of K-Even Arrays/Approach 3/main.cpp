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

        vector<
            vector<
                array<long long, 2>
            >
        > dp(
            n,
            vector<array<long long, 2>>(
                k + 1
            )
        );

        dp[0][0][0] =
            oddChoices;

        dp[0][0][1] =
            evenChoices;

        for (int index = 1;
             index < n;
             index++) {
            for (int count = 0;
                 count <= k;
                 count++) {
                long long totalPrevious =
                    (
                        dp[index - 1][count][0] +
                        dp[index - 1][count][1]
                    ) %
                    MOD;

                dp[index][count][0] =
                    totalPrevious *
                    oddChoices %
                    MOD;

                dp[index][count][1] =
                    dp[index - 1][count][0] *
                    evenChoices %
                    MOD;

                if (count > 0) {
                    dp[index][count][1] =
                        (
                            dp[index][count][1] +
                            dp[index - 1][count - 1][1] *
                            evenChoices
                        ) %
                        MOD;
                }
            }
        }

        return static_cast<int>(
            (
                dp[n - 1][k][0] +
                dp[n - 1][k][1]
            ) %
            MOD
        );
    }
};
