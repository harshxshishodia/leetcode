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

        vector<int> best(
            states,
            INF
        );

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pending;

        best[0] = 0;
        pending.push({
            0,
            0
        });

        while (!pending.empty()) {
            auto [cost, mask] =
                pending.top();

            pending.pop();

            if (cost != best[mask]) {
                continue;
            }

            int worker =
                __builtin_popcount(
                    static_cast<unsigned int>(mask)
                );

            if (worker ==
                static_cast<int>(workers.size())) {
                return cost;
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

                int nextCost =
                    cost +
                    distance(
                        workers[worker],
                        bikes[bike]
                    );

                if (nextCost < best[nextMask]) {
                    best[nextMask] =
                        nextCost;

                    pending.push({
                        nextCost,
                        nextMask
                    });
                }
            }
        }

        return -1;
    }
};
