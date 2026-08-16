class HitCounter {
    int timestamps[300];
    int hitCounts[300];

public:
    HitCounter() {
        for (int i = 0; i < 300; i++) {
            timestamps[i] = 0;
            hitCounts[i] = 0;
        }
    }

    void hit(int timestamp) {
        int index = timestamp % 300;
        if (timestamps[index] != timestamp) {
            timestamps[index] = timestamp;
            hitCounts[index] = 1;
        } else {
            hitCounts[index]++;
        }
    }

    int getHits(int timestamp) {
        int total = 0;
        for (int i = 0; i < 300; i++) {
            if (timestamp - timestamps[i] < 300) {
                total += hitCounts[i];
            }
        }
        return total;
    }
};
