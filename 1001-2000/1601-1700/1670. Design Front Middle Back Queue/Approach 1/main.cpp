class FrontMiddleBackQueue {
    vector<int> elements;

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        elements.insert(elements.begin(), val);
    }

    void pushMiddle(int val) {
        int midIndex = elements.size() / 2;
        elements.insert(elements.begin() + midIndex, val);
    }

    void pushBack(int val) {
        elements.push_back(val);
    }

    int popFront() {
        if (elements.empty()) return -1;
        int val = elements.front();
        elements.erase(elements.begin());
        return val;
    }

    int popMiddle() {
        if (elements.empty()) return -1;
        int midIndex = (elements.size() - 1) / 2;
        int val = elements[midIndex];
        elements.erase(elements.begin() + midIndex);
        return val;
    }

    int popBack() {
        if (elements.empty()) return -1;
        int val = elements.back();
        elements.pop_back();
        return val;
    }
};
