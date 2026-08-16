class MedianFinder {
    priority_queue<int> lowerHalfMaxHeap;
    priority_queue<int, vector<int>, greater<int>> upperHalfMinHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (lowerHalfMaxHeap.empty() || num <= lowerHalfMaxHeap.top()) {
            lowerHalfMaxHeap.push(num);
        } else {
            upperHalfMinHeap.push(num);
        }

        if (lowerHalfMaxHeap.size() > upperHalfMinHeap.size() + 1) {
            upperHalfMinHeap.push(lowerHalfMaxHeap.top());
            lowerHalfMaxHeap.pop();
        } else if (upperHalfMinHeap.size() > lowerHalfMaxHeap.size()) {
            lowerHalfMaxHeap.push(upperHalfMinHeap.top());
            upperHalfMinHeap.pop();
        }
    }

    double findMedian() {
        if (lowerHalfMaxHeap.size() > upperHalfMinHeap.size()) {
            return lowerHalfMaxHeap.top();
        } else {
            return (lowerHalfMaxHeap.top() + upperHalfMinHeap.top()) / 2.0;
        }
    }
};
