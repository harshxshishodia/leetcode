class HitCounter {
    queue<int> hitTimestamps;

public:
    HitCounter() {}

    void hit(int timestamp) {
        hitTimestamps.push(timestamp);
    }

    int getHits(int timestamp) {
        while (!hitTimestamps.empty() && timestamp - hitTimestamps.front() >= 300) {
            hitTimestamps.pop();
        }
        return static_cast<int>(hitTimestamps.size());
    }
};
