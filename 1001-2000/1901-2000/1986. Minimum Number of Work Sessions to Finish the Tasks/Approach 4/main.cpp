class Solution {
public:
    int minSessions(
        vector<int>& tasks,
        int sessionTime
    ) {
        int n =
            static_cast<int>(tasks.size());

        int states =
            1 << n;

        pair<int, int> INF = {
            n + 1,
            0
        };

        vector<pair<int, int>> dp(
            states,
            INF
        );

        dp[0] = {
            1,
            0
        };

        for (int mask = 0; mask < states; mask++) {
            if (dp[mask].first > n) {
                continue;
            }

            for (int index = 0; index < n; index++) {
                int bit =
                    1 << index;

                if ((mask & bit) != 0) {
                    continue;
                }

                pair<int, int> candidate =
                    dp[mask];

                if (candidate.second +
                    tasks[index] <=
                    sessionTime) {
                    candidate.second +=
                        tasks[index];
                } else {
                    candidate.first++;
                    candidate.second =
                        tasks[index];
                }

                if (candidate <
                    dp[mask | bit]) {
                    dp[mask | bit] =
                        candidate;
                }
            }
        }

        return dp[states - 1].first;
    }
};
