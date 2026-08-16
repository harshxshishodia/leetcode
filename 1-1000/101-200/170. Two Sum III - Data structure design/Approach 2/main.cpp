class TwoSum {
    vector<int> numbers;
    bool isSorted;

public:
    TwoSum() : isSorted(true) {}

    void add(int number) {
        numbers.push_back(number);
        isSorted = false;
    }

    bool find(int value) {
        if (!isSorted) {
            sort(numbers.begin(), numbers.end());
            isSorted = true;
        }
        int left = 0;
        int right = static_cast<int>(numbers.size()) - 1;
        while (left < right) {
            long long currentSum = static_cast<long long>(numbers[left]) + numbers[right];
            if (currentSum == value) {
                return true;
            } else if (currentSum < value) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};
