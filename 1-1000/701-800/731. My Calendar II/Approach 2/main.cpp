class MyCalendarTwo {
    map<int, int> boundaryCountDelta;

public:
    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
        boundaryCountDelta[startTime]++;
        boundaryCountDelta[endTime]--;

        int activeBookings = 0;
        for (const auto& [time, delta] : boundaryCountDelta) {
            activeBookings += delta;
            if (activeBookings >= 3) {
                boundaryCountDelta[startTime]--;
                boundaryCountDelta[endTime]++;
                return false;
            }
        }
        return true;
    }
};
