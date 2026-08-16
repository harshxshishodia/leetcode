class RecentCounter {
    queue<int> pingQueue;

public:
    RecentCounter() {}

    int ping(int t) {
        pingQueue.push(t);
        while (!pingQueue.empty() && pingQueue.front() < t - 3000) {
            pingQueue.pop();
        }
        return static_cast<int>(pingQueue.size());
    }
};
