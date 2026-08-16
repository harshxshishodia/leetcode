class MyCalendarTwo {
    vector<pair<int, int>> singleBookings;
    vector<pair<int, int>> doubleBookings;

public:
    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
        for (const auto& [overlapStart, overlapEnd] : doubleBookings) {
            if (max(startTime, overlapStart) < min(endTime, overlapEnd)) {
                return false;
            }
        }

        for (const auto& [bookingStart, bookingEnd] : singleBookings) {
            if (max(startTime, bookingStart) < min(endTime, bookingEnd)) {
                doubleBookings.emplace_back(max(startTime, bookingStart), min(endTime, bookingEnd));
            }
        }

        singleBookings.emplace_back(startTime, endTime);
        return true;
    }
};
