class Cashier {
    int nthCustomerThreshold;
    int discountRate;
    int customerCount;
    unordered_map<int, int> productPriceMap;

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices)
        : nthCustomerThreshold(n), discountRate(discount), customerCount(0) {
        for (int i = 0; i < static_cast<int>(products.size()); i++) {
            productPriceMap[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        customerCount++;
        double totalBill = 0.0;
        for (int i = 0; i < static_cast<int>(product.size()); i++) {
            totalBill += productPriceMap[product[i]] * amount[i];
        }
        if (customerCount % nthCustomerThreshold == 0) {
            totalBill = totalBill * (100.0 - discountRate) / 100.0;
        }
        return totalBill;
    }
};
