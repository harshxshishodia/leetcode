class MovingAverage {
    queue<int> windowQueue;
    int windowSize;
    double runningSum;

public:
    MovingAverage(int size) : windowSize(size), runningSum(0.0) {}

    double next(int val) {
        windowQueue.push(val);
        runningSum += val;
        if (static_cast<int>(windowQueue.size()) > windowSize) {
            runningSum -= windowQueue.front();
            windowQueue.pop();
        }
        return runningSum / windowQueue.size();
    }
};
