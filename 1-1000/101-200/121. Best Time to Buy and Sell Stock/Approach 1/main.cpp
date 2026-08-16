class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestProfit = 0;

        for (int buy = 0; buy < static_cast<int>(prices.size()); buy++) {
            for (int sell = buy + 1; sell < static_cast<int>(prices.size()); sell++) {
                bestProfit = max(bestProfit, prices[sell] - prices[buy]);
            }
        }

        return bestProfit;
    }
};
