class RideSharingSystem {
    queue<int> waitingRidersQueue;
    queue<int> availableDriversQueue;
    unordered_set<int> activeRiderSet;

public:
    RideSharingSystem() {}

    void addRider(int riderId) {
        waitingRidersQueue.push(riderId);
        activeRiderSet.insert(riderId);
    }

    void addDriver(int driverId) {
        availableDriversQueue.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        while (!waitingRidersQueue.empty() && !activeRiderSet.count(waitingRidersQueue.front())) {
            waitingRidersQueue.pop();
        }

        if (availableDriversQueue.empty() || waitingRidersQueue.empty()) {
            return {-1, -1};
        }

        int matchedDriverId = availableDriversQueue.front();
        availableDriversQueue.pop();
        int matchedRiderId = waitingRidersQueue.front();
        waitingRidersQueue.pop();
        activeRiderSet.erase(matchedRiderId);

        return {matchedDriverId, matchedRiderId};
    }

    void cancelRider(int riderId) {
        activeRiderSet.erase(riderId);
    }
};
