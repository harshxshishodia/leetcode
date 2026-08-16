class StockPrice {
    unordered_map<int, int> timestampToPrice;
    map<int, int> priceCountMap;
    int latestTimestamp;

public:
    StockPrice() : latestTimestamp(0) {}

    void update(int timestamp, int price) {
        latestTimestamp = max(latestTimestamp, timestamp);
        if (timestampToPrice.count(timestamp)) {
            int oldPrice = timestampToPrice[timestamp];
            if (--priceCountMap[oldPrice] == 0) {
                priceCountMap.erase(oldPrice);
            }
        }
        timestampToPrice[timestamp] = price;
        priceCountMap[price]++;
    }

    int current() {
        return timestampToPrice[latestTimestamp];
    }

    int maximum() {
        return priceCountMap.rbegin()->first;
    }

    int minimum() {
        return priceCountMap.begin()->first;
    }
};
