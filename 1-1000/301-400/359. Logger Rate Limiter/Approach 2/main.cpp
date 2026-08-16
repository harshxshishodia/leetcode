class Logger {
    unordered_map<string, int> nextAllowedTime;

public:
    Logger() {}

    bool shouldPrintMessage(int timestamp, string message) {
        auto it = nextAllowedTime.find(message);
        if (it == nextAllowedTime.end() || timestamp >= it->second) {
            nextAllowedTime[message] = timestamp + 10;
            return true;
        }
        return false;
    }
};
