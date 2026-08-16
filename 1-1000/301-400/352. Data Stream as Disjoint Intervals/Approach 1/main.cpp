class SummaryRanges {
    map<int, int> intervalMap; // start -> end

public:
    SummaryRanges() {}

    void addNum(int value) {
        auto nextInterval = intervalMap.upper_bound(value);
        auto prevInterval = (nextInterval == intervalMap.begin()) ? intervalMap.end() : prev(nextInterval);

        if (prevInterval != intervalMap.end() && prevInterval->second >= value) {
            return;
        }

        bool mergePrev = (prevInterval != intervalMap.end() && prevInterval->second + 1 == value);
        bool mergeNext = (nextInterval != intervalMap.end() && nextInterval->first == value + 1);

        if (mergePrev && mergeNext) {
            prevInterval->second = nextInterval->second;
            intervalMap.erase(nextInterval);
        } else if (mergePrev) {
            prevInterval->second = value;
        } else if (mergeNext) {
            int nextEnd = nextInterval->second;
            intervalMap.erase(nextInterval);
            intervalMap[value] = nextEnd;
        } else {
            intervalMap[value] = value;
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (const auto& [start, end] : intervalMap) {
            result.push_back({start, end});
        }
        return result;
    }
};
