class RangeModule {
    vector<pair<int, int>> ranges;

public:
    RangeModule() {
    }

    void addRange(int left, int right) {
        vector<pair<int, int>> merged;
        int newLeft = left;
        int newRight = right;
        bool inserted = false;

        for (const pair<int, int>& range : ranges) {
            if (range.second < newLeft) {
                merged.push_back(range);
            } else if (newRight < range.first) {
                if (!inserted) {
                    merged.push_back({newLeft, newRight});
                    inserted = true;
                }

                merged.push_back(range);
            } else {
                newLeft = min(newLeft, range.first);
                newRight = max(newRight, range.second);
            }
        }

        if (!inserted)
            merged.push_back({newLeft, newRight});

        ranges = merged;
    }

    bool queryRange(int left, int right) {
        for (const pair<int, int>& range : ranges) {
            if (range.first > left)
                break;

            if (range.first <= left && range.second >= right)
                return true;
        }

        return false;
    }

    void removeRange(int left, int right) {
        vector<pair<int, int>> remaining;

        for (const pair<int, int>& range : ranges) {
            if (range.second <= left || range.first >= right) {
                remaining.push_back(range);
                continue;
            }

            if (range.first < left)
                remaining.push_back({range.first, left});

            if (range.second > right)
                remaining.push_back({right, range.second});
        }

        ranges = remaining;
    }
};