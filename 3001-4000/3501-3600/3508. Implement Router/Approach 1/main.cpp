class Router {
    int maxMemoryLimit;
    deque<tuple<int, int, int>> packetQueue; // (source, destination, timestamp)
    set<tuple<int, int, int>> packetSet;
    unordered_map<int, deque<int>> destinationTimestamps;

public:
    Router(int memoryLimit) : maxMemoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        auto packet = make_tuple(source, destination, timestamp);
        if (packetSet.count(packet)) {
            return false;
        }

        if (static_cast<int>(packetQueue.size()) == maxMemoryLimit) {
            auto oldestPacket = packetQueue.front();
            packetQueue.pop_front();
            packetSet.erase(oldestPacket);
            int oldDest = get<1>(oldestPacket);
            destinationTimestamps[oldDest].pop_front();
        }

        packetQueue.push_back(packet);
        packetSet.insert(packet);
        destinationTimestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (packetQueue.empty()) {
            return {};
        }
        auto packet = packetQueue.front();
        packetQueue.pop_front();
        packetSet.erase(packet);
        auto [src, dst, ts] = packet;
        destinationTimestamps[dst].pop_front();
        return {src, dst, ts};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destinationTimestamps.find(destination);
        if (it == destinationTimestamps.end()) {
            return 0;
        }
        const auto& timestampList = it->second;
        auto low = lower_bound(timestampList.begin(), timestampList.end(), startTime);
        auto high = upper_bound(timestampList.begin(), timestampList.end(), endTime);
        return high - low;
    }
};
