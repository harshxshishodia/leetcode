class OrderManagementSystem {
    unordered_map<int, pair<string, int>> orderDetailsMap;
    unordered_map<string, unordered_map<int, unordered_set<int>>> priceLevelOrders;

public:
    OrderManagementSystem() {}

    void addOrder(int orderId, string orderType, int price) {
        orderDetailsMap[orderId] = {orderType, price};
        priceLevelOrders[orderType][price].insert(orderId);
    }

    void modifyOrder(int orderId, int newPrice) {
        auto& [type, oldPrice] = orderDetailsMap[orderId];
        priceLevelOrders[type][oldPrice].erase(orderId);
        oldPrice = newPrice;
        priceLevelOrders[type][newPrice].insert(orderId);
    }

    void cancelOrder(int orderId) {
        auto [type, price] = orderDetailsMap[orderId];
        priceLevelOrders[type][price].erase(orderId);
        orderDetailsMap.erase(orderId);
    }

    vector<int> getOrdersAtPrice(string orderType, int price) {
        vector<int> resultOrderIds;
        auto itType = priceLevelOrders.find(orderType);
        if (itType != priceLevelOrders.end()) {
            auto itPrice = itType->second.find(price);
            if (itPrice != itType->second.end()) {
                resultOrderIds.assign(itPrice->second.begin(), itPrice->second.end());
            }
        }
        return resultOrderIds;
    }
};
