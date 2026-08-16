class BrowserHistory {
    vector<string> historyList;
    int currentIndex;
    int maxAvailableIndex;

public:
    BrowserHistory(string homepage) : historyList({homepage}), currentIndex(0), maxAvailableIndex(0) {}

    void visit(string url) {
        currentIndex++;
        if (currentIndex < static_cast<int>(historyList.size())) {
            historyList[currentIndex] = url;
        } else {
            historyList.push_back(url);
        }
        maxAvailableIndex = currentIndex;
    }

    string back(int steps) {
        currentIndex = max(0, currentIndex - steps);
        return historyList[currentIndex];
    }

    string forward(int steps) {
        currentIndex = min(maxAvailableIndex, currentIndex + steps);
        return historyList[currentIndex];
    }
};
