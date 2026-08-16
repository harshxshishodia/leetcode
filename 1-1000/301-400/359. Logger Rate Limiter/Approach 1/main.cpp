class Logger {
    queue<pair<string, int>> messageQueue;
    unordered_set<string> activeMessages;

public:
    Logger() {}

    bool shouldPrintMessage(int timestamp, string message) {
        while (!messageQueue.empty() && timestamp - messageQueue.front().second >= 10) {
            activeMessages.erase(messageQueue.front().first);
            messageQueue.pop();
        }

        if (activeMessages.find(message) == activeMessages.end()) {
            messageQueue.push({message, timestamp});
            activeMessages.insert(message);
            return true;
        }

        return false;
    }
};
