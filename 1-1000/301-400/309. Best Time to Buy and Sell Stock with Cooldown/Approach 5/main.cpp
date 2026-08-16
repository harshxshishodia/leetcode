class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int hold = -prices[0];
        int sold = 0;
        int rest = 0;

        for (int i = 1; i < static_cast<int>(prices.size()); i++) {
            int previousHold = hold;
            int previousSold = sold;
            int previousRest = rest;

            hold = max(
                previousHold,
                previousRest - prices[i]
            );

            sold = previousHold + prices[i];
            rest = max(previousRest, previousSold);
        }

        return max(sold, rest);
    }
};
