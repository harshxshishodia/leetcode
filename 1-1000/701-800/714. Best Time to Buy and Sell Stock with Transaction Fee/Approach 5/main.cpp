class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0;
        int effectiveBuy =
            prices[0] + fee;

        for (int i = 1; i < static_cast<int>(prices.size()); i++) {
            effectiveBuy = min(
                effectiveBuy,
                prices[i] + fee
            );

            if (prices[i] > effectiveBuy) {
                profit +=
                    prices[i] - effectiveBuy;

                effectiveBuy =
                    prices[i];
            }
        }

        return profit;
    }
};
