class DataStream {
    int targetValue;
    int requiredConsecutiveCount;
    int currentStreak;

public:
    DataStream(int value, int k)
        : targetValue(value), requiredConsecutiveCount(k), currentStreak(0) {}

    bool consec(int num) {
        if (num == targetValue) {
            currentStreak++;
        } else {
            currentStreak = 0;
        }
        return currentStreak >= requiredConsecutiveCount;
    }
};
