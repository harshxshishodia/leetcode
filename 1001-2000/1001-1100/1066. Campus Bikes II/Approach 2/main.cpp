class Solution {
    vector<int> memo;

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
        int mask
    ) {
        int worker =
            __builtin_popcount(
                static_cast<unsigned int>(mask)
            );

        if (worker ==
            static_cast<int>(workers.size())) {
            return 0;
        }

        if (memo[mask] != -1) {
            return memo[mask];
        }

        int answer =
            numeric_limits<int>::max();

        for (int bike = 0;
             bike < static_cast<int>(bikes.size());
             bike++) {
            int bit =
                1 << bike;

            if ((mask & bit) != 0) {
                continue;
            }

            answer = min(
                answer,
                distance(
                    workers[worker],
                    bikes[bike]
                ) +
                solve(
                    workers,
                    bikes,
                    mask | bit
                )
            );
        }

        memo[mask] = answer;
        return memo[mask];
    }

public:
    int assignBikes(
        vector<vector<int>>& workers,
        vector<vector<int>>& bikes
    ) {
        memo.assign(
            1 << bikes.size(),
            -1
        );

        return solve(
            workers,
            bikes,
            0
        );
    }
};
