class LogSystem {
    vector<pair<string, int>> logList;
    unordered_map<string, int> granularityLength = {
        {"Year", 4},
        {"Month", 7},
        {"Day", 10},
        {"Hour", 13},
        {"Minute", 16},
        {"Second", 19}
    };

public:
    LogSystem() {}

    void put(int id, string timestamp) {
        logList.emplace_back(timestamp, id);
    }

    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> matchingIds;
        int len = granularityLength[granularity];
        string startPrefix = start.substr(0, len);
        string endPrefix = end.substr(0, len);

        for (const auto& [ts, id] : logList) {
            string tsPrefix = ts.substr(0, len);
            if (tsPrefix >= startPrefix && tsPrefix <= endPrefix) {
                matchingIds.push_back(id);
            }
        }
        return matchingIds;
    }
};
