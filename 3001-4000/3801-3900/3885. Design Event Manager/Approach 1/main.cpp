class EventManager {
    unordered_map<int, int> eventPriorityMap;
    set<pair<int, int>> eventQueueSet; // (-priority, eventId)

public:
    EventManager(vector<vector<int>>& events) {
        for (const auto& event : events) {
            int eventId = event[0];
            int priority = event[1];
            eventPriorityMap[eventId] = priority;
            eventQueueSet.insert({-priority, eventId});
        }
    }

    void updatePriority(int eventId, int newPriority) {
        if (eventPriorityMap.count(eventId)) {
            int oldPriority = eventPriorityMap[eventId];
            eventQueueSet.erase({-oldPriority, eventId});
            eventPriorityMap[eventId] = newPriority;
            eventQueueSet.insert({-newPriority, eventId});
        }
    }

    int pollHighest() {
        if (eventQueueSet.empty()) {
            return -1;
        }
        auto it = eventQueueSet.begin();
        int highestEventId = it->second;
        eventQueueSet.erase(it);
        eventPriorityMap.erase(highestEventId);
        return highestEventId;
    }
};
