class Solution {
public:
    int maximumProfit(
        vector<int>& present,
        vector<int>& future,
        int budget
    ) {
        int n =
            static_cast<int>(present.size());

        vector<vector<int>> dp(
            n + 1,
            vector<int>(
                budget + 1
            )
        );

        for (int index = 1; index <= n; index++) {
            int cost =
                present[index - 1];

            int profit =
                future[index - 1] -
                present[index - 1];

            for (int money = 0;
                 money <= budget;
                 money++) {
                dp[index][money] =
                    dp[index - 1][money];

                if (cost <= money) {
                    dp[index][money] = max(
                        dp[index][money],
                        profit +
                        dp[index - 1][
                            money - cost
                        ]
                    );
                }
            }
        }

        return dp[n][budget];
    }
};
