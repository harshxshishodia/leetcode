class ProductOfNumbers {
    vector<int> prefixProducts;

public:
    ProductOfNumbers() : prefixProducts({1}) {}

    void add(int num) {
        if (num == 0) {
            prefixProducts = {1};
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }

    int getProduct(int k) {
        int n = static_cast<int>(prefixProducts.size());
        if (k >= n) return 0;
        return prefixProducts.back() / prefixProducts[n - 1 - k];
    }
};
