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

        vector<int> sum(states);

        vector<bool> feasible(states);

        feasible[0] = true;

        for (int mask = 1; mask < states; mask++) {
            int bit =
                __builtin_ctz(
                    static_cast<unsigned int>(mask)
                );

            int previous =
                mask &
                (mask - 1);

            sum[mask] =
                sum[previous] +
                tasks[bit];

            feasible[mask] =
                sum[mask] <=
                sessionTime;
        }

        vector<int> dp(
            states,
            n + 1
        );

        dp[0] = 0;

        for (int mask = 1; mask < states; mask++) {
            for (int submask = mask;
                 submask > 0;
                 submask =
                 (submask - 1) & mask) {
                if (feasible[submask]) {
                    dp[mask] = min(
                        dp[mask],
                        1 +
                        dp[
                            mask ^ submask
                        ]
                    );
                }
            }
        }

        return dp[states - 1];
    }
};
