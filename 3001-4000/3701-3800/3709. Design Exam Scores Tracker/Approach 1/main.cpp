class ExamTracker {
    vector<int> examTimes;
    vector<long long> scorePrefixSums;

public:
    ExamTracker() {
        scorePrefixSums.push_back(0);
    }

    void record(int time, int score) {
        examTimes.push_back(time);
        scorePrefixSums.push_back(scorePrefixSums.back() + score);
    }

    long long totalScore(int startTime, int endTime) {
        auto low = lower_bound(examTimes.begin(), examTimes.end(), startTime);
        auto high = upper_bound(examTimes.begin(), examTimes.end(), endTime);

        int leftIndex = low - examTimes.begin();
        int rightIndex = high - examTimes.begin();

        if (leftIndex >= rightIndex) return 0;
        return scorePrefixSums[rightIndex] - scorePrefixSums[leftIndex];
    }
};
