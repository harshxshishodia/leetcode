class FrontMiddleBackQueue {
    deque<int> leftHalf;
    deque<int> rightHalf;

    void balanceDeques() {
        if (leftHalf.size() > rightHalf.size() + 1) {
            rightHalf.push_front(leftHalf.back());
            leftHalf.pop_back();
        } else if (leftHalf.size() < rightHalf.size()) {
            leftHalf.push_back(rightHalf.front());
            rightHalf.pop_front();
        }
    }

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        leftHalf.push_front(val);
        balanceDeques();
    }

    void pushMiddle(int val) {
        if (leftHalf.size() > rightHalf.size()) {
            rightHalf.push_front(leftHalf.back());
            leftHalf.pop_back();
        }
        leftHalf.push_back(val);
        balanceDeques();
    }

    void pushBack(int val) {
        rightHalf.push_back(val);
        balanceDeques();
    }

    int popFront() {
        if (leftHalf.empty() && rightHalf.empty()) return -1;
        int val = leftHalf.front();
        leftHalf.pop_front();
        balanceDeques();
        return val;
    }

    int popMiddle() {
        if (leftHalf.empty() && rightHalf.empty()) return -1;
        int val;
        if (leftHalf.size() == rightHalf.size()) {
            val = leftHalf.back();
            leftHalf.pop_back();
        } else {
            val = leftHalf.back();
            leftHalf.pop_back();
        }
        balanceDeques();
        return val;
    }

    int popBack() {
        if (leftHalf.empty() && rightHalf.empty()) return -1;
        int val;
        if (!rightHalf.empty()) {
            val = rightHalf.back();
            rightHalf.pop_back();
        } else {
            val = leftHalf.back();
            leftHalf.pop_back();
        }
        balanceDeques();
        return val;
    }
};
