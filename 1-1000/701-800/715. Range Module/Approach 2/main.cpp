class RangeModule {
    map<int, int> ranges;

public:
    RangeModule() {
    }

    void addRange(int left, int right) {
        auto iterator = ranges.lower_bound(left);

        if (iterator != ranges.begin()) {
            auto previousIterator = prev(iterator);

            if (previousIterator->second >= left)
                iterator = previousIterator;
        }

        while (iterator != ranges.end() && iterator->first <= right) {
            if (iterator->second < left) {
                iterator++;
                continue;
            }

            left = min(left, iterator->first);
            right = max(right, iterator->second);
            iterator = ranges.erase(iterator);
        }

        ranges[left] = right;
    }

    bool queryRange(int left, int right) {
        auto iterator = ranges.upper_bound(left);

        if (iterator == ranges.begin())
            return false;

        iterator--;
        return iterator->second >= right;
    }

    void removeRange(int left, int right) {
        auto iterator = ranges.lower_bound(left);

        if (iterator != ranges.begin()) {
            auto previousIterator = prev(iterator);

            if (previousIterator->second > left)
                iterator = previousIterator;
        }

        vector<pair<int, int>> remaining;

        while (iterator != ranges.end() && iterator->first < right) {
            int currentLeft = iterator->first;
            int currentRight = iterator->second;

            if (currentRight <= left) {
                iterator++;
                continue;
            }

            if (currentLeft < left)
                remaining.push_back({currentLeft, left});

            if (currentRight > right)
                remaining.push_back({right, currentRight});

            iterator = ranges.erase(iterator);
        }

        for (const pair<int, int>& range : remaining)
            ranges[range.first] = range.second;
    }
};