class UndergroundSystem {
    unordered_map<int, pair<string, int>> passengerCheckIns;
    unordered_map<string, pair<long long, int>> routeTravelStats; // "start->end" -> (totalTime, count)

public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        passengerCheckIns[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = passengerCheckIns[id];
        passengerCheckIns.erase(id);
        string routeKey = startStation + "->" + stationName;
        routeTravelStats[routeKey].first += (t - startTime);
        routeTravelStats[routeKey].second++;
    }

    double getAverageTime(string startStation, string endStation) {
        string routeKey = startStation + "->" + endStation;
        const auto& [totalDuration, tripCount] = routeTravelStats[routeKey];
        return static_cast<double>(totalDuration) / tripCount;
    }
};
