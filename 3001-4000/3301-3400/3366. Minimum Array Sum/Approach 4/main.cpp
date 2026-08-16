class Solution {
public:
    int minArraySum(
        vector<int>& nums,
        int k,
        int op1,
        int op2
    ) {
        const int INF =
            1000000000;

        vector<vector<int>> dp(
            op1 + 1,
            vector<int>(
                op2 + 1,
                INF
            )
        );

        dp[0][0] =
            0;

        for (int value :
             nums) {
            vector<vector<int>> next(
                op1 + 1,
                vector<int>(
                    op2 + 1,
                    INF
                )
            );

            for (int used1 = 0;
                 used1 <= op1;
                 used1++) {
                for (int used2 = 0;
                     used2 <= op2;
                     used2++) {
                    if (dp[used1][used2] == INF) {
                        continue;
                    }

                    int current =
                        dp[used1][used2];

                    next[used1][used2] = min(
                        next[used1][used2],
                        current +
                        value
                    );

                    if (used1 < op1) {
                        next[used1 + 1][used2] = min(
                            next[used1 + 1][used2],
                            current +
                            (
                                value +
                                1
                            ) /
                            2
                        );
                    }

                    if (used2 < op2 &&
                        value >= k) {
                        next[used1][used2 + 1] = min(
                            next[used1][used2 + 1],
                            current +
                            value -
                            k
                        );
                    }

                    if (used1 < op1 &&
                        used2 < op2) {
                        int half =
                            (
                                value +
                                1
                            ) /
                            2;

                        if (half >= k) {
                            next[used1 + 1][used2 + 1] = min(
                                next[used1 + 1][used2 + 1],
                                current +
                                half -
                                k
                            );
                        }

                        if (value >= k) {
                            next[used1 + 1][used2 + 1] = min(
                                next[used1 + 1][used2 + 1],
                                current +
                                (
                                    value -
                                    k +
                                    1
                                ) /
                                2
                            );
                        }
                    }
                }
            }

            dp.swap(
                next
            );
        }

        int answer =
            INF;

        for (int used1 = 0;
             used1 <= op1;
             used1++) {
            for (int used2 = 0;
                 used2 <= op2;
                 used2++) {
                answer = min(
                    answer,
                    dp[used1][used2]
                );
            }
        }

        return answer;
    }
};
