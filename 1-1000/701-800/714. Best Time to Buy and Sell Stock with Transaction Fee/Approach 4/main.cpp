class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int nextCanBuy = 0;
        int nextHolding = 0;

        for (int index = static_cast<int>(prices.size()) - 1;
             index >= 0;
             index--) {
            int currentCanBuy = max(
                nextCanBuy,
                -prices[index] + nextHolding
            );

            int currentHolding = max(
                nextHolding,
                prices[index] -
                fee +
                nextCanBuy
            );

            nextCanBuy = currentCanBuy;
            nextHolding = currentHolding;
        }

        return nextCanBuy;
    }
};
