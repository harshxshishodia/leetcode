class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;

        for (int value = 2; value <= n; value++) {
            for (int first = 1; first < value; first++) {
                int remaining = value - first;

                dp[value] = max(
                    dp[value],
                    first * max(
                        remaining,
                        dp[remaining]
                    )
                );
            }
        }

        return dp[n];
    }
};
