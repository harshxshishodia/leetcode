class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) return "";

        const auto& records = it->second;
        int left = 0, right = static_cast<int>(records.size()) - 1;
        int matchedIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (records[mid].first <= timestamp) {
                matchedIndex = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return matchedIndex == -1 ? "" : records[matchedIndex].second;
    }
};
