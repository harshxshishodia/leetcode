class TwoSum {
    vector<int> numbers;

public:
    TwoSum() {}

    void add(int number) {
        numbers.push_back(number);
    }

    bool find(int value) {
        int n = static_cast<int>(numbers.size());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (static_cast<long long>(numbers[i]) + numbers[j] == value) {
                    return true;
                }
            }
        }
        return false;
    }
};
