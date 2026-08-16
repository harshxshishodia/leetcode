class Solution {
public:
    int maximumProfit(
        vector<int>& present,
        vector<int>& future,
        int budget
    ) {
        vector<int> dp(
            budget + 1
        );

        for (int index = 0;
             index < static_cast<int>(present.size());
             index++) {
            int cost =
                present[index];

            int profit =
                future[index] -
                present[index];

            if (profit <= 0) {
                continue;
            }

            for (int money = budget;
                 money >= cost;
                 money--) {
                dp[money] = max(
                    dp[money],
                    profit +
                    dp[money - cost]
                );
            }
        }

        return dp[budget];
    }
};
