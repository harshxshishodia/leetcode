class MapSum {
    unordered_map<string, int> keyValueStore;

public:
    MapSum() {}

    void insert(string key, int val) {
        keyValueStore[key] = val;
    }

    int sum(string prefix) {
        int totalSum = 0;
        int prefixLen = static_cast<int>(prefix.size());
        for (const auto& [key, val] : keyValueStore) {
            if (key.size() >= prefixLen && key.substr(0, prefixLen) == prefix) {
                totalSum += val;
            }
        }
        return totalSum;
    }
};
