class RangeModule {
    map<int, int> disjointIntervals; // start -> end

public:
    RangeModule() {}

    void addRange(int left, int right) {
        auto it = disjointIntervals.upper_bound(left);
        if (it != disjointIntervals.begin() && prev(it)->second >= left) {
            it--;
        }
        while (it != disjointIntervals.end() && it->first <= right) {
            left = min(left, it->first);
            right = max(right, it->second);
            it = disjointIntervals.erase(it);
        }
        disjointIntervals[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = disjointIntervals.upper_bound(left);
        if (it == disjointIntervals.begin()) return false;
        it--;
        return it->first <= left && it->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = disjointIntervals.upper_bound(left);
        if (it != disjointIntervals.begin() && prev(it)->second > left) {
            it--;
        }
        vector<pair<int, int>> remainingSubIntervals;
        while (it != disjointIntervals.end() && it->first < right) {
            if (it->first < left) {
                remainingSubIntervals.emplace_back(it->first, left);
            }
            if (it->second > right) {
                remainingSubIntervals.emplace_back(right, it->second);
            }
            it = disjointIntervals.erase(it);
        }
        for (const auto& [start, end] : remainingSubIntervals) {
            disjointIntervals[start] = end;
        }
    }
};
