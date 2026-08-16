class TwoSum {
    unordered_map<long long, int> frequencyMap;

public:
    TwoSum() {}

    void add(int number) {
        frequencyMap[number]++;
    }

    bool find(int value) {
        for (const auto& [num, count] : frequencyMap) {
            long long complement = static_cast<long long>(value) - num;
            if (complement == num) {
                if (count >= 2) {
                    return true;
                }
            } else {
                if (frequencyMap.find(complement) != frequencyMap.end()) {
                    return true;
                }
            }
        }
        return false;
    }
};
