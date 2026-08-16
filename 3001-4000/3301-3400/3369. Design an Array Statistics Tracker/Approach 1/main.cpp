class StatisticsTracker {
    queue<int> elementQueue;
    multiset<int> lowerHalfMedian, upperHalfMedian;
    unordered_map<int, int> elementFrequencies;
    map<int, set<int>> frequencyToElements;
    long long runningSum;

    void balanceMedianHeaps() {
        while (lowerHalfMedian.size() > upperHalfMedian.size() + 1) {
            auto it = prev(lowerHalfMedian.end());
            upperHalfMedian.insert(*it);
            lowerHalfMedian.erase(it);
        }
        while (lowerHalfMedian.size() < upperHalfMedian.size()) {
            auto it = upperHalfMedian.begin();
            lowerHalfMedian.insert(*it);
            upperHalfMedian.erase(it);
        }
    }

public:
    StatisticsTracker() : runningSum(0) {}

    void addNumber(int number) {
        elementQueue.push(number);
        runningSum += number;

        if (lowerHalfMedian.empty() || number <= *lowerHalfMedian.rbegin()) {
            lowerHalfMedian.insert(number);
        } else {
            upperHalfMedian.insert(number);
        }
        balanceMedianHeaps();

        int oldFreq = elementFrequencies[number]++;
        if (oldFreq > 0) {
            frequencyToElements[oldFreq].erase(number);
            if (frequencyToElements[oldFreq].empty()) {
                frequencyToElements.erase(oldFreq);
            }
        }
        frequencyToElements[oldFreq + 1].insert(number);
    }

    void removeFirstAddedNumber() {
        int num = elementQueue.front();
        elementQueue.pop();
        runningSum -= num;

        if (lowerHalfMedian.find(num) != lowerHalfMedian.end()) {
            lowerHalfMedian.erase(lowerHalfMedian.find(num));
        } else {
            upperHalfMedian.erase(upperHalfMedian.find(num));
        }
        balanceMedianHeaps();

        int oldFreq = elementFrequencies[num]--;
        frequencyToElements[oldFreq].erase(num);
        if (frequencyToElements[oldFreq].empty()) {
            frequencyToElements.erase(oldFreq);
        }
        if (oldFreq - 1 > 0) {
            frequencyToElements[oldFreq - 1].insert(num);
        }
    }

    int getMean() {
        return runningSum / elementQueue.size();
    }

    int getMedian() {
        return *lowerHalfMedian.rbegin();
    }

    int getMode() {
        return *frequencyToElements.rbegin()->second.begin();
    }
};
