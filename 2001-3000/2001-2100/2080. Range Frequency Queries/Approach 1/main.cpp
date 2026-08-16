class RangeFreqQuery {
    unordered_map<int, vector<int>> valueIndicesMap;

public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < static_cast<int>(arr.size()); i++) {
            valueIndicesMap[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        auto it = valueIndicesMap.find(value);
        if (it == valueIndicesMap.end()) return 0;
        const auto& indices = it->second;
        auto low = lower_bound(indices.begin(), indices.end(), left);
        auto high = upper_bound(indices.begin(), indices.end(), right);
        return high - low;
    }
};
