class Solution {
    int solve(vector<int>& prices, int index, bool canBuy) {
        if (index == static_cast<int>(prices.size())) {
            return 0;
        }

        if (canBuy) {
            int skip = solve(prices, index + 1, true);
            int buy = -prices[index] + solve(prices, index + 1, false);
            return max(skip, buy);
        }

        int skip = solve(prices, index + 1, false);
        int sell = prices[index];
        return max(skip, sell);
    }

public:
    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, true);
    }
};
