class Solution {
public:
    int numberOfStableArrays(
        int zero,
        int one,
        int limit
    ) {
        const int MOD =
            1000000007;

        vector<vector<vector<vector<int>>>> dp(
            zero + 1,
            vector<vector<vector<int>>>(
                one + 1,
                vector<vector<int>>(
                    2,
                    vector<int>(
                        limit + 1
                    )
                )
            )
        );

        if (zero > 0) {
            dp[1][0][0][1] =
                1;
        }

        if (one > 0) {
            dp[0][1][1][1] =
                1;
        }

        for (int z = 0;
             z <= zero;
             z++) {
            for (int o = 0;
                 o <= one;
                 o++) {
                for (int last = 0;
                     last <= 1;
                     last++) {
                    for (int run = 1;
                         run <= limit;
                         run++) {
                        int ways =
                            dp[z][o][last][run];

                        if (ways == 0) {
                            continue;
                        }

                        if (
                            z < zero &&
                            (
                                last != 0 ||
                                run < limit
                            )
                        ) {
                            int nextRun =
                                last == 0
                                    ? run + 1
                                    : 1;

                            dp[z + 1][o][0][nextRun] =
                                (
                                    dp[z + 1][o][0][nextRun] +
                                    ways
                                ) %
                                MOD;
                        }

                        if (
                            o < one &&
                            (
                                last != 1 ||
                                run < limit
                            )
                        ) {
                            int nextRun =
                                last == 1
                                    ? run + 1
                                    : 1;

                            dp[z][o + 1][1][nextRun] =
                                (
                                    dp[z][o + 1][1][nextRun] +
                                    ways
                                ) %
                                MOD;
                        }
                    }
                }
            }
        }

        long long answer = 0;

        for (int run = 1;
             run <= limit;
             run++) {
            answer +=
                dp[zero][one][0][run];

            answer +=
                dp[zero][one][1][run];
        }

        return static_cast<int>(
            answer %
            MOD
        );
    }
};
