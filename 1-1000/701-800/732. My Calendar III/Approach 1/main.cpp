class MyCalendarThree {
    map<int, int> timelineBoundaryCount;

public:
    MyCalendarThree() {}

    int book(int startTime, int endTime) {
        timelineBoundaryCount[startTime]++;
        timelineBoundaryCount[endTime]--;

        int ongoingEvents = 0;
        int maxSimultaneousEvents = 0;

        for (const auto& [time, delta] : timelineBoundaryCount) {
            ongoingEvents += delta;
            maxSimultaneousEvents = max(maxSimultaneousEvents, ongoingEvents);
        }
        return maxSimultaneousEvents;
    }
};
