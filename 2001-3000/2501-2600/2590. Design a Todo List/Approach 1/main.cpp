class TodoList {
    struct TaskItem {
        int taskId;
        string taskDescription;
        int dueDate;
        unordered_set<string> tags;
        bool isCompleted = false;
    };

    int nextTaskIdCounter;
    unordered_map<int, vector<TaskItem>> userTaskList;

public:
    TodoList() : nextTaskIdCounter(1) {}

    int addTask(int userId, string taskDescription, int dueDate, vector<string> tags) {
        int taskId = nextTaskIdCounter++;
        TaskItem item;
        item.taskId = taskId;
        item.taskDescription = taskDescription;
        item.dueDate = dueDate;
        item.tags = unordered_set<string>(tags.begin(), tags.end());
        item.isCompleted = false;
        userTaskList[userId].push_back(item);
        return taskId;
    }

    vector<string> getAllTasks(int userId) {
        vector<string> descriptions;
        if (!userTaskList.count(userId)) return descriptions;

        vector<TaskItem> activeTasks;
        for (const auto& task : userTaskList[userId]) {
            if (!task.isCompleted) {
                activeTasks.push_back(task);
            }
        }
        sort(activeTasks.begin(), activeTasks.end(), [](const TaskItem& a, const TaskItem& b) {
            return a.dueDate < b.dueDate;
        });
        for (const auto& task : activeTasks) {
            descriptions.push_back(task.taskDescription);
        }
        return descriptions;
    }

    vector<string> getTasksForTag(int userId, string tag) {
        vector<string> descriptions;
        if (!userTaskList.count(userId)) return descriptions;

        vector<TaskItem> activeTasks;
        for (const auto& task : userTaskList[userId]) {
            if (!task.isCompleted && task.tags.count(tag)) {
                activeTasks.push_back(task);
            }
        }
        sort(activeTasks.begin(), activeTasks.end(), [](const TaskItem& a, const TaskItem& b) {
            return a.dueDate < b.dueDate;
        });
        for (const auto& task : activeTasks) {
            descriptions.push_back(task.taskDescription);
        }
        return descriptions;
    }

    void completeTask(int userId, int taskId) {
        if (!userTaskList.count(userId)) return;
        for (auto& task : userTaskList[userId]) {
            if (task.taskId == taskId) {
                task.isCompleted = true;
                break;
            }
        }
    }
};
