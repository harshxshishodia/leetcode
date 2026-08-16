class MedianFinder {
    vector<int> numbers;

public:
    MedianFinder() {}

    void addNum(int num) {
        auto it = lower_bound(numbers.begin(), numbers.end(), num);
        numbers.insert(it, num);
    }

    double findMedian() {
        int n = static_cast<int>(numbers.size());
        if (n % 2 == 1) {
            return numbers[n / 2];
        } else {
            return (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
        }
    }
};
