class TweetCounts {
    unordered_map<string, multiset<int>> tweetRecords;

public:
    TweetCounts() {}

    void recordTweet(string tweetName, int time) {
        tweetRecords[tweetName].insert(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int intervalSeconds = 60;
        if (freq == "hour") intervalSeconds = 3600;
        else if (freq == "day") intervalSeconds = 86400;

        int chunkCount = (endTime - startTime) / intervalSeconds + 1;
        vector<int> result(chunkCount, 0);

        auto it = tweetRecords.find(tweetName);
        if (it == tweetRecords.end()) return result;

        const auto& times = it->second;
        auto low = times.lower_bound(startTime);
        auto high = times.upper_bound(endTime);

        for (auto iter = low; iter != high; iter++) {
            int chunkIndex = (*iter - startTime) / intervalSeconds;
            result[chunkIndex]++;
        }
        return result;
    }
};
