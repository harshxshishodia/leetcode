class Solution {
public:
    long long minCost(
        int n,
        vector<vector<int>>& cost
    ) {
        const long long INF =
            numeric_limits<long long>::max() /
            4;

        array<array<long long, 3>, 3> previous;

        for (auto& row :
             previous) {
            row.fill(
                INF
            );
        }

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

                previous[leftColor][rightColor] =
                    1LL *
                    cost[0][leftColor] +
                    cost[n - 1][rightColor];
            }
        }

        for (int pairIndex = 1;
             pairIndex < n / 2;
             pairIndex++) {
            array<array<long long, 3>, 3> current;

            for (auto& row :
                 current) {
                row.fill(
                    INF
                );
            }

            int right =
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
                            if (previousRight ==
                                rightColor) {
                                continue;
                            }

                            current[leftColor][rightColor] =
                                min(
                                    current[leftColor][rightColor],
                                    previous[previousLeft][previousRight] +
                                    cost[pairIndex][leftColor] +
                                    cost[right][rightColor]
                                );
                        }
                    }
                }
            }

            previous =
                current;
        }

        long long answer =
            INF;

        for (const auto& row :
             previous) {
            for (long long value :
                 row) {
                answer = min(
                    answer,
                    value
                );
            }
        }

        return answer;
    }
};
