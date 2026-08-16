class Solution {
    int distance(
        const vector<int>& worker,
        const vector<int>& bike
    ) {
        return
            abs(worker[0] - bike[0]) +
            abs(worker[1] - bike[1]);
    }

public:
    int assignBikes(
        vector<vector<int>>& workers,
        vector<vector<int>>& bikes
    ) {
        int states =
            1 << bikes.size();

        const int INF =
            1000000000;

        vector<int> dp(
            states,
            INF
        );

        dp[0] = 0;

        for (int mask = 0; mask < states; mask++) {
            int worker =
                __builtin_popcount(
                    static_cast<unsigned int>(mask)
                );

            if (worker >=
                    static_cast<int>(workers.size()) ||
                dp[mask] == INF) {
                continue;
            }

            for (int bike = 0;
                 bike < static_cast<int>(bikes.size());
                 bike++) {
                int bit =
                    1 << bike;

                if ((mask & bit) != 0) {
                    continue;
                }

                int nextMask =
                    mask | bit;

                dp[nextMask] = min(
                    dp[nextMask],
                    dp[mask] +
                    distance(
                        workers[worker],
                        bikes[bike]
                    )
                );
            }
        }

        int answer = INF;
        int workersCount =
            static_cast<int>(workers.size());

        for (int mask = 0; mask < states; mask++) {
            if (__builtin_popcount(
                    static_cast<unsigned int>(mask)) ==
                workersCount) {
                answer = min(
                    answer,
                    dp[mask]
                );
            }
        }

        return answer;
    }
};
