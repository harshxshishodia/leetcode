class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int nextCanBuy = 0;
        int nextHolding = 0;
        int nextNextCanBuy = 0;

        for (int index = static_cast<int>(prices.size()) - 1;
             index >= 0;
             index--) {
            int currentCanBuy = max(
                nextCanBuy,
                -prices[index] + nextHolding
            );

            int currentHolding = max(
                nextHolding,
                prices[index] + nextNextCanBuy
            );

            nextNextCanBuy = nextCanBuy;
            nextCanBuy = currentCanBuy;
            nextHolding = currentHolding;
        }

        return nextCanBuy;
    }
};
