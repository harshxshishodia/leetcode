class Solution {
    int distance(
        const vector<int>& worker,
        const vector<int>& bike
    ) {
        return
            abs(worker[0] - bike[0]) +
            abs(worker[1] - bike[1]);
    }

    int solve(
        const vector<vector<int>>& workers,
        const vector<vector<int>>& bikes,
        int worker,
        vector<bool>& used
    ) {
        if (worker == static_cast<int>(workers.size())) {
            return 0;
        }

        int answer =
            numeric_limits<int>::max();

        for (int bike = 0;
             bike < static_cast<int>(bikes.size());
             bike++) {
            if (used[bike]) {
                continue;
            }

            used[bike] = true;

            answer = min(
                answer,
                distance(
                    workers[worker],
                    bikes[bike]
                ) +
                solve(
                    workers,
                    bikes,
                    worker + 1,
                    used
                )
            );

            used[bike] = false;
        }

        return answer;
    }

public:
    int assignBikes(
        vector<vector<int>>& workers,
        vector<vector<int>>& bikes
    ) {
        vector<bool> used(
            bikes.size()
        );

        return solve(
            workers,
            bikes,
            0,
            used
        );
    }
};
