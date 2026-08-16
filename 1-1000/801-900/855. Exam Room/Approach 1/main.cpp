class ExamRoom {
    int totalSeats;
    set<int> occupiedSeats;

public:
    ExamRoom(int n) : totalSeats(n) {}

    int seat() {
        if (occupiedSeats.empty()) {
            occupiedSeats.insert(0);
            return 0;
        }

        int maxDistance = *occupiedSeats.begin();
        int bestSeatPosition = 0;
        int previousSeat = -1;

        for (int s : occupiedSeats) {
            if (previousSeat != -1) {
                int distance = (s - previousSeat) / 2;
                if (distance > maxDistance) {
                    maxDistance = distance;
                    bestSeatPosition = previousSeat + distance;
                }
            }
            previousSeat = s;
        }

        if (totalSeats - 1 - *occupiedSeats.rbegin() > maxDistance) {
            bestSeatPosition = totalSeats - 1;
        }

        occupiedSeats.insert(bestSeatPosition);
        return bestSeatPosition;
    }

    void leave(int p) {
        occupiedSeats.erase(p);
    }
};
