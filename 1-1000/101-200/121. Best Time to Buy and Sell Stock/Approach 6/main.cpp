class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestEndingHere = 0;
        int bestProfit = 0;

        for (int i = 1; i < static_cast<int>(prices.size()); i++) {
            int difference = prices[i] - prices[i - 1];
            bestEndingHere = max(0, bestEndingHere + difference);
            bestProfit = max(bestProfit, bestEndingHere);
        }

        return bestProfit;
    }
};
