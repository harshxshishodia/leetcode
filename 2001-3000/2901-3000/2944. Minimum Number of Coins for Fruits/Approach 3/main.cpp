class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n =
            static_cast<int>(prices.size());

        vector<int> dp(
            n + 1
        );

        for (int index = n - 1;
             index >= 0;
             index--) {
            dp[index] =
                numeric_limits<int>::max();

            int right =
                min(
                    n,
                    2 *
                    index +
                    2
                );

            for (int next =
                     index +
                     1;
                 next <= right;
                 next++) {
                dp[index] = min(
                    dp[index],
                    prices[index] +
                    dp[next]
                );
            }
        }

        return dp[0];
    }
};
