class Solution {
public:
    double probabilityOfHeads(
        vector<double>& prob,
        int target
    ) {
        vector<double> dp(
            target + 1
        );

        dp[0] = 1.0;

        for (double probability : prob) {
            for (int heads = target;
                 heads >= 1;
                 heads--) {
                dp[heads] =
                    dp[heads] *
                    (1.0 - probability) +
                    dp[heads - 1] *
                    probability;
            }

            dp[0] *=
                1.0 - probability;
        }

        return dp[target];
    }
};
