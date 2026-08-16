class MajorityChecker {
    vector<int> arrayData;
    unordered_map<int, vector<int>> valueIndicesMap;

    int getFrequencyInRange(int val, int left, int right) {
        const auto& indices = valueIndicesMap[val];
        auto low = lower_bound(indices.begin(), indices.end(), left);
        auto high = upper_bound(indices.begin(), indices.end(), right);
        return high - low;
    }

public:
    MajorityChecker(vector<int>& arr) : arrayData(arr) {
        for (int i = 0; i < static_cast<int>(arr.size()); i++) {
            valueIndicesMap[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int threshold) {
        int length = right - left + 1;
        for (int iter = 0; iter < 20; iter++) {
            int randomIndex = left + rand() % length;
            int candidate = arrayData[randomIndex];
            if (getFrequencyInRange(candidate, left, right) >= threshold) {
                return candidate;
            }
        }
        return -1;
    }
};
