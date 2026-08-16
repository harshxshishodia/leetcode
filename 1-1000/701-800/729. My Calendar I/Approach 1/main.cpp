class MyCalendar {
    vector<pair<int, int>> bookingsList;

public:
    MyCalendar() {}

    bool book(int startTime, int endTime) {
        for (const auto& [start, end] : bookingsList) {
            if (max(startTime, start) < min(endTime, end)) {
                return false;
            }
        }
        bookingsList.emplace_back(startTime, endTime);
        return true;
    }
};
