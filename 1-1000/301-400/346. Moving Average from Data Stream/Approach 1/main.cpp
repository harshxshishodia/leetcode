class MovingAverage {
    vector<int> streamData;
    int windowCapacity;

public:
    MovingAverage(int size) : windowCapacity(size) {}

    double next(int val) {
        streamData.push_back(val);
        int count = min(windowCapacity, static_cast<int>(streamData.size()));
        double sum = 0.0;
        int startIndex = static_cast<int>(streamData.size()) - count;
        for (int i = startIndex; i < static_cast<int>(streamData.size()); i++) {
            sum += streamData[i];
        }
        return sum / count;
    }
};
