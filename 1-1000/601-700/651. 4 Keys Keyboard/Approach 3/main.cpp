class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1);

        for (int operations = 1;
             operations <= n;
             operations++) {
            dp[operations] = operations;

            for (int breakpoint = 1;
                 breakpoint <= operations - 3;
                 breakpoint++) {
                int pastes =
                    operations - breakpoint - 2;

                dp[operations] = max(
                    dp[operations],
                    dp[breakpoint] * (pastes + 1)
                );
            }
        }

        return dp[n];
    }
};
