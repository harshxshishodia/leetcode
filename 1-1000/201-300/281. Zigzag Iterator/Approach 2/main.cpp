class ZigzagIterator {
    queue<pair<vector<int>::iterator, vector<int>::iterator>> vectorQueue;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            vectorQueue.push({v1.begin(), v1.end()});
        }
        if (!v2.empty()) {
            vectorQueue.push({v2.begin(), v2.end()});
        }
    }

    int next() {
        auto [currentIter, endIter] = vectorQueue.front();
        vectorQueue.pop();
        int value = *currentIter;
        if (++currentIter != endIter) {
            vectorQueue.push({currentIter, endIter});
        }
        return value;
    }

    bool hasNext() {
        return !vectorQueue.empty();
    }
};
