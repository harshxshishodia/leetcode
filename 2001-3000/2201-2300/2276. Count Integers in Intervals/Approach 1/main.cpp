class CountIntervals {
    map<int, int> intervalMap; // start -> end
    int totalCount;

public:
    CountIntervals() : totalCount(0) {}

    void add(int left, int right) {
        auto it = intervalMap.upper_bound(left);
        if (it != intervalMap.begin() && prev(it)->second >= left) {
            it--;
        }
        while (it != intervalMap.end() && it->first <= right) {
            left = min(left, it->first);
            right = max(right, it->second);
            totalCount -= (it->second - it->first + 1);
            it = intervalMap.erase(it);
        }
        intervalMap[left] = right;
        totalCount += (right - left + 1);
    }

    int count() {
        return totalCount;
    }
};
