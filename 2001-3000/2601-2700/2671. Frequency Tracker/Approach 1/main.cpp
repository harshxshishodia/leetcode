class FrequencyTracker {
    unordered_map<int, int> numberFrequency;
    unordered_map<int, int> frequencyCounts;

public:
    FrequencyTracker() {}

    void add(int number) {
        int oldFreq = numberFrequency[number];
        if (oldFreq > 0) {
            frequencyCounts[oldFreq]--;
        }
        int newFreq = oldFreq + 1;
        numberFrequency[number] = newFreq;
        frequencyCounts[newFreq]++;
    }

    void deleteOne(int number) {
        int oldFreq = numberFrequency[number];
        if (oldFreq == 0) return;

        frequencyCounts[oldFreq]--;
        int newFreq = oldFreq - 1;
        if (newFreq > 0) {
            numberFrequency[number] = newFreq;
            frequencyCounts[newFreq]++;
        } else {
            numberFrequency.erase(number);
        }
    }

    bool hasFrequency(int frequency) {
        auto it = frequencyCounts.find(frequency);
        return it != frequencyCounts.end() && it->second > 0;
    }
};
