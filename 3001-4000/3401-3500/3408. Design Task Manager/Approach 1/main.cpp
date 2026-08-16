class TaskManager {
    set<tuple<int, int, int>> taskPrioritySet; // (-priority, -taskId, userId)
    unordered_map<int, pair<int, int>> taskDetailsMap; // taskId -> (userId, priority)

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskDetailsMap[taskId] = {userId, priority};
        taskPrioritySet.insert({-priority, -taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = taskDetailsMap[taskId];
        taskPrioritySet.erase({-oldPriority, -taskId, userId});
        taskDetailsMap[taskId] = {userId, newPriority};
        taskPrioritySet.insert({-newPriority, -taskId, userId});
    }

    void rmv(int taskId) {
        auto [userId, priority] = taskDetailsMap[taskId];
        taskPrioritySet.erase({-priority, -taskId, userId});
        taskDetailsMap.erase(taskId);
    }

    int execTop() {
        if (taskPrioritySet.empty()) return -1;
        auto [negPriority, negTaskId, userId] = *taskPrioritySet.begin();
        int taskId = -negTaskId;
        taskPrioritySet.erase(taskPrioritySet.begin());
        taskDetailsMap.erase(taskId);
        return userId;
    }
};
