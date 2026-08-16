class SeatManager {
    priority_queue<int, vector<int>, greater<int>> availableSeatsHeap;

public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            availableSeatsHeap.push(i);
        }
    }

    int reserve() {
        int reservedSeat = availableSeatsHeap.top();
        availableSeatsHeap.pop();
        return reservedSeat;
    }

    void unreserve(int seatNumber) {
        availableSeatsHeap.push(seatNumber);
    }
};
