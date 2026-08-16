class MyCalendar {
    map<int, int> scheduledBookings; // start -> end

public:
    MyCalendar() {}

    bool book(int startTime, int endTime) {
        auto nextBooking = scheduledBookings.upper_bound(startTime);
        if (nextBooking != scheduledBookings.end() && nextBooking->first < endTime) {
            return false;
        }
        if (nextBooking != scheduledBookings.begin()) {
            auto prevBooking = prev(nextBooking);
            if (prevBooking->second > startTime) {
                return false;
            }
        }
        scheduledBookings[startTime] = endTime;
        return true;
    }
};
