class StockSpanner {
    stack<pair<int, int>> monotonicStack; // pair of (price, span)

public:
    StockSpanner() {}

    int next(int price) {
        int currentSpan = 1;
        while (!monotonicStack.empty() && monotonicStack.top().first <= price) {
            currentSpan += monotonicStack.top().second;
            monotonicStack.pop();
        }
        monotonicStack.emplace(price, currentSpan);
        return currentSpan;
    }
};
