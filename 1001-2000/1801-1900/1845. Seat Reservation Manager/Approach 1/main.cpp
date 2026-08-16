class SeatManager {
    vector<bool> seatReserved;
    int maxSeats;

public:
    SeatManager(int n) : maxSeats(n), seatReserved(n + 1, false) {}

    int reserve() {
        for (int i = 1; i <= maxSeats; i++) {
            if (!seatReserved[i]) {
                seatReserved[i] = true;
                return i;
            }
        }
        return -1;
    }

    void unreserve(int seatNumber) {
        seatReserved[seatNumber] = false;
    }
};
