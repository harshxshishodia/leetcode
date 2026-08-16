class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1);

        for (int operations = 1;
             operations <= n;
             operations++) {
            dp[operations] = operations;

            if (operations >= 4) {
                dp[operations] = max(
                    dp[operations],
                    2 * dp[operations - 3]
                );
            }

            if (operations >= 5) {
                dp[operations] = max(
                    dp[operations],
                    3 * dp[operations - 4]
                );
            }

            if (operations >= 6) {
                dp[operations] = max(
                    dp[operations],
                    4 * dp[operations - 5]
                );
            }
        }

        return dp[n];
    }
};
