class Solution {
    int answer;

    void search(
        const vector<int>& tasks,
        int sessionTime,
        int index,
        vector<int>& sessions
    ) {
        if (static_cast<int>(sessions.size()) >= answer) {
            return;
        }

        if (index == static_cast<int>(tasks.size())) {
            answer = min(
                answer,
                static_cast<int>(sessions.size())
            );

            return;
        }

        int task =
            tasks[index];

        for (int session = 0;
             session < static_cast<int>(sessions.size());
             session++) {
            if (sessions[session] + task >
                sessionTime) {
                continue;
            }

            bool duplicate = false;

            for (int previous = 0;
                 previous < session;
                 previous++) {
                if (sessions[previous] ==
                    sessions[session]) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                continue;
            }

            sessions[session] += task;

            search(
                tasks,
                sessionTime,
                index + 1,
                sessions
            );

            sessions[session] -= task;
        }

        sessions.push_back(task);

        search(
            tasks,
            sessionTime,
            index + 1,
            sessions
        );

        sessions.pop_back();
    }

public:
    int minSessions(
        vector<int>& tasks,
        int sessionTime
    ) {
        sort(
            tasks.begin(),
            tasks.end(),
            greater<int>()
        );

        answer =
            static_cast<int>(tasks.size());

        vector<int> sessions;

        search(
            tasks,
            sessionTime,
            0,
            sessions
        );

        return answer;
    }
};
