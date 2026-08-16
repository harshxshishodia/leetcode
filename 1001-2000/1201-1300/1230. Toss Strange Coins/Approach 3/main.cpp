class Solution {
public:
    double probabilityOfHeads(
        vector<double>& prob,
        int target
    ) {
        int n =
            static_cast<int>(prob.size());

        vector<vector<double>> dp(
            n + 1,
            vector<double>(
                target + 1
            )
        );

        dp[0][0] = 1.0;

        for (int index = 1; index <= n; index++) {
            dp[index][0] =
                dp[index - 1][0] *
                (1.0 - prob[index - 1]);

            for (int heads = 1;
                 heads <= target;
                 heads++) {
                dp[index][heads] =
                    dp[index - 1][heads] *
                    (1.0 - prob[index - 1]) +
                    dp[index - 1][heads - 1] *
                    prob[index - 1];
            }
        }

        return dp[n][target];
    }
};
