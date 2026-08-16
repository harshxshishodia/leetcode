class Solution {
public:
    long long minCost(
        int n,
        vector<vector<int>>& cost
    ) {
        const long long INF =
            numeric_limits<long long>::max() /
            4;

        vector<array<array<long long, 3>, 3>> dp(
            n / 2
        );

        for (auto& layer :
             dp) {
            for (auto& row :
                 layer) {
                row.fill(
                    INF
                );
            }
        }

        int right =
            n -
            1;

        for (int leftColor = 0;
             leftColor < 3;
             leftColor++) {
            for (int rightColor = 0;
                 rightColor < 3;
                 rightColor++) {
                if (leftColor ==
                    rightColor) {
                    continue;
                }

                dp[0][leftColor][rightColor] =
                    1LL *
                    cost[0][leftColor] +
                    cost[right][rightColor];
            }
        }

        for (int pairIndex = 1;
             pairIndex < n / 2;
             pairIndex++) {
            int left =
                pairIndex;

            right =
                n -
                1 -
                pairIndex;

            for (int leftColor = 0;
                 leftColor < 3;
                 leftColor++) {
                for (int rightColor = 0;
                     rightColor < 3;
                     rightColor++) {
                    if (leftColor ==
                        rightColor) {
                        continue;
                    }

                    for (int previousLeft = 0;
                         previousLeft < 3;
                         previousLeft++) {
                        if (previousLeft ==
                            leftColor) {
                            continue;
                        }

                        for (int previousRight = 0;
                             previousRight < 3;
                             previousRight++) {
                            if (
                                previousRight ==
                                    rightColor ||
                                dp[pairIndex - 1][previousLeft][previousRight] ==
                                    INF
                            ) {
                                continue;
                            }

                            dp[pairIndex][leftColor][rightColor] =
                                min(
                                    dp[pairIndex][leftColor][rightColor],
                                    dp[pairIndex - 1][previousLeft][previousRight] +
                                    cost[left][leftColor] +
                                    cost[right][rightColor]
                                );
                        }
                    }
                }
            }
        }

        long long answer =
            INF;

        for (int leftColor = 0;
             leftColor < 3;
             leftColor++) {
            for (int rightColor = 0;
                 rightColor < 3;
                 rightColor++) {
                answer = min(
                    answer,
                    dp[n / 2 - 1][leftColor][rightColor]
                );
            }
        }

        return answer;
    }
};
