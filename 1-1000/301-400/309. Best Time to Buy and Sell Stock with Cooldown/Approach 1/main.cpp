class Solution {
    int solve(
        const vector<int>& prices,
        int index,
        bool canBuy
    ) {
        if (index >= static_cast<int>(prices.size())) {
            return 0;
        }

        if (canBuy) {
            return max(
                solve(prices, index + 1, true),
                -prices[index] + solve(prices, index + 1, false)
            );
        }

        return max(
            solve(prices, index + 1, false),
            prices[index] + solve(prices, index + 2, true)
        );
    }

public:
    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, true);
    }
};
