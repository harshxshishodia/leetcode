class Solution {
public:
    int findMinimumTime(
        vector<int>& strength,
        int K
    ) {
        int n =
            static_cast<int>(strength.size());

        int states =
            1 << n;

        const int INF =
            1000000000;

        vector<int> dp(
            states,
            INF
        );

        dp[0] =
            0;

        for (int mask = 0;
             mask < states;
             mask++) {
            if (dp[mask] == INF) {
                continue;
            }

            int broken =
                __builtin_popcount(
                    static_cast<unsigned int>(mask)
                );

            int factor =
                1 +
                broken *
                K;

            for (int index = 0;
                 index < n;
                 index++) {
                if ((mask & (1 << index)) != 0) {
                    continue;
                }

                int minutes =
                    (
                        strength[index] +
                        factor -
                        1
                    ) /
                    factor;

                int nextMask =
                    mask |
                    (1 << index);

                dp[nextMask] = min(
                    dp[nextMask],
                    dp[mask] +
                    minutes
                );
            }
        }

        return dp[states - 1];
    }
};
