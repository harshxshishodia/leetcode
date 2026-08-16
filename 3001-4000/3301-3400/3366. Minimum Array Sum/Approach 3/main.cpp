class Solution {
public:
    int minArraySum(
        vector<int>& nums,
        int k,
        int op1,
        int op2
    ) {
        int n =
            static_cast<int>(nums.size());

        const int INF =
            1000000000;

        vector<
            vector<
                vector<int>
            >
        > dp(
            n + 1,
            vector<vector<int>>(
                op1 + 1,
                vector<int>(
                    op2 + 1,
                    INF
                )
            )
        );

        dp[0][0][0] =
            0;

        for (int index = 0;
             index < n;
             index++) {
            int value =
                nums[index];

            for (int used1 = 0;
                 used1 <= op1;
                 used1++) {
                for (int used2 = 0;
                     used2 <= op2;
                     used2++) {
                    if (dp[index][used1][used2] == INF) {
                        continue;
                    }

                    int current =
                        dp[index][used1][used2];

                    dp[index + 1][used1][used2] = min(
                        dp[index + 1][used1][used2],
                        current +
                        value
                    );

                    if (used1 < op1) {
                        dp[index + 1][used1 + 1][used2] = min(
                            dp[index + 1][used1 + 1][used2],
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
                        dp[index + 1][used1][used2 + 1] = min(
                            dp[index + 1][used1][used2 + 1],
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
                            dp[index + 1][used1 + 1][used2 + 1] = min(
                                dp[index + 1][used1 + 1][used2 + 1],
                                current +
                                half -
                                k
                            );
                        }

                        if (value >= k) {
                            dp[index + 1][used1 + 1][used2 + 1] = min(
                                dp[index + 1][used1 + 1][used2 + 1],
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
                    dp[n][used1][used2]
                );
            }
        }

        return answer;
    }
};
