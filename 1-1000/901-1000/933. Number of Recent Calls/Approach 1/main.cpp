class RecentCounter {
    vector<int> pings;

public:
    RecentCounter() {}

    int ping(int t) {
        pings.push_back(t);
        auto it = lower_bound(pings.begin(), pings.end(), t - 3000);
        return static_cast<int>(pings.end() - it);
    }
};
