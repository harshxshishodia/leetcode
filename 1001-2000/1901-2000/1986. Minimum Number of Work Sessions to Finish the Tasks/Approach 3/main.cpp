class Solution {
    vector<int> memo;
    int sessionTime;
    int fullMask;

    int solve(
        const vector<int>& tasks,
        int mask,
        int remaining
    ) {
        if (mask == fullMask) {
            return 0;
        }

        int key =
            mask *
            (sessionTime + 1) +
            remaining;

        if (memo[key] != -1) {
            return memo[key];
        }

        int answer =
            static_cast<int>(tasks.size());

        for (int index = 0;
             index < static_cast<int>(tasks.size());
             index++) {
            int bit =
                1 << index;

            if ((mask & bit) != 0) {
                continue;
            }

            if (tasks[index] <= remaining) {
                answer = min(
                    answer,
                    solve(
                        tasks,
                        mask | bit,
                        remaining -
                        tasks[index]
                    )
                );
            } else {
                answer = min(
                    answer,
                    1 +
                    solve(
                        tasks,
                        mask | bit,
                        sessionTime -
                        tasks[index]
                    )
                );
            }
        }

        memo[key] =
            answer;

        return memo[key];
    }

public:
    int minSessions(
        vector<int>& tasks,
        int inputSessionTime
    ) {
        sessionTime =
            inputSessionTime;

        fullMask =
            (1 << tasks.size()) -
            1;

        memo.assign(
            (1 << tasks.size()) *
            (sessionTime + 1),
            -1
        );

        return solve(
            tasks,
            0,
            0
        );
    }
};
