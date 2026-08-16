class ProductOfNumbers {
    vector<int> numbers;

public:
    ProductOfNumbers() {}

    void add(int num) {
        numbers.push_back(num);
    }

    int getProduct(int k) {
        int product = 1;
        int n = static_cast<int>(numbers.size());
        for (int i = n - k; i < n; i++) {
            product *= numbers[i];
        }
        return product;
    }
};
