class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumPrice = numeric_limits<int>::max();
        int bestProfit = 0;

        for (int price : prices) {
            minimumPrice = min(minimumPrice, price);
            bestProfit = max(bestProfit, price - minimumPrice);
        }

        return bestProfit;
    }
};
