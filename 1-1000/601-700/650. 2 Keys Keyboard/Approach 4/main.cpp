class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);

        for (int value = 2; value <= n; value++) {
            dp[value] = value;

            for (int divisor = 1;
                 divisor * divisor <= value;
                 divisor++) {
                if (value % divisor != 0) {
                    continue;
                }

                int other = value / divisor;

                dp[value] = min(
                    dp[value],
                    dp[divisor] + other
                );

                dp[value] = min(
                    dp[value],
                    dp[other] + divisor
                );
            }
        }

        return dp[n];
    }
};
