class StockSpanner {
    vector<int> priceHistory;

public:
    StockSpanner() {}

    int next(int price) {
        priceHistory.push_back(price);
        int span = 0;
        for (int i = static_cast<int>(priceHistory.size()) - 1; i >= 0; i--) {
            if (priceHistory[i] <= price) {
                span++;
            } else {
                break;
            }
        }
        return span;
    }
};
