class Solution {
    vector<array<array<long long, 4>, 4>> memo;
    vector<array<array<bool, 4>, 4>> visited;

    long long solve(
        const vector<vector<int>>& cost,
        int pairIndex,
        int previousLeft,
        int previousRight
    ) {
        int n =
            static_cast<int>(cost.size());

        if (pairIndex == n / 2) {
            return 0;
        }

        if (
            visited[pairIndex][previousLeft][previousRight]
        ) {
            return
                memo[pairIndex][previousLeft][previousRight];
        }

        visited[pairIndex][previousLeft][previousRight] =
            true;

        int left =
            pairIndex;

        int right =
            n -
            1 -
            pairIndex;

        long long answer =
            numeric_limits<long long>::max() /
            4;

        for (int leftColor = 0;
             leftColor < 3;
             leftColor++) {
            if (leftColor ==
                previousLeft) {
                continue;
            }

            for (int rightColor = 0;
                 rightColor < 3;
                 rightColor++) {
                if (
                    rightColor ==
                        previousRight ||
                    rightColor ==
                        leftColor
                ) {
                    continue;
                }

                answer = min(
                    answer,
                    1LL *
                        cost[left][leftColor] +
                        cost[right][rightColor] +
                        solve(
                            cost,
                            pairIndex + 1,
                            leftColor,
                            rightColor
                        )
                );
            }
        }

        memo[pairIndex][previousLeft][previousRight] =
            answer;

        return answer;
    }

public:
    long long minCost(
        int n,
        vector<vector<int>>& cost
    ) {
        memo.assign(
            n / 2,
            {}
        );

        visited.assign(
            n / 2,
            {}
        );

        return solve(
            cost,
            0,
            3,
            3
        );
    }
};
