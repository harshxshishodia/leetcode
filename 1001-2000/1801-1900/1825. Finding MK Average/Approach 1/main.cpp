class MKAverage {
    int mWindow, kElements;
    queue<int> streamQueue;
    multiset<int> leftSmallest, middleElements, rightLargest;
    long long middleSum;

    void addElement(int num) {
        leftSmallest.insert(num);
        if (leftSmallest.size() > kElements) {
            auto it = prev(leftSmallest.end());
            middleElements.insert(*it);
            middleSum += *it;
            leftSmallest.erase(it);
        }
        if (middleElements.size() > mWindow - 2 * kElements) {
            auto it = prev(middleElements.end());
            rightLargest.insert(*it);
            middleSum -= *it;
            middleElements.erase(it);
        }
    }

    void removeElement(int num) {
        if (leftSmallest.find(num) != leftSmallest.end()) {
            leftSmallest.erase(leftSmallest.find(num));
            auto it = middleElements.begin();
            leftSmallest.insert(*it);
            middleSum -= *it;
            middleElements.erase(it);
            auto it2 = rightLargest.begin();
            middleElements.insert(*it2);
            middleSum += *it2;
            rightLargest.erase(it2);
        } else if (middleElements.find(num) != middleElements.end()) {
            middleElements.erase(middleElements.find(num));
            middleSum -= num;
            auto it = rightLargest.begin();
            middleElements.insert(*it);
            middleSum += *it;
            rightLargest.erase(it);
        } else {
            rightLargest.erase(rightLargest.find(num));
        }
    }

public:
    MKAverage(int m, int k) : mWindow(m), kElements(k), middleSum(0) {}

    void addElementNum(int num) {
        streamQueue.push(num);
        if (static_cast<int>(streamQueue.size()) <= mWindow) {
            addElement(num);
        } else {
            addElement(num);
            int oldest = streamQueue.front();
            streamQueue.pop();
            removeElement(oldest);
        }
    }

    int calculateMKAverage() {
        if (static_cast<int>(streamQueue.size()) < mWindow) return -1;
        return middleSum / (mWindow - 2 * kElements);
    }
};
