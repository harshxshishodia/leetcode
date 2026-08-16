class Solution {
    long long answer =
        numeric_limits<long long>::max();

    void search(
        const vector<vector<int>>& cost,
        int index,
        vector<int>& colors,
        long long total
    ) {
        int n =
            static_cast<int>(cost.size());

        if (index == n) {
            for (int house = 1;
                 house < n;
                 house++) {
                if (colors[house] ==
                    colors[house - 1]) {
                    return;
                }
            }

            for (int house = 0;
                 house < n / 2;
                 house++) {
                if (
                    colors[house] ==
                    colors[n - 1 - house]
                ) {
                    return;
                }
            }

            answer = min(
                answer,
                total
            );

            return;
        }

        for (int color = 0;
             color < 3;
             color++) {
            colors[index] =
                color;

            search(
                cost,
                index + 1,
                colors,
                total +
                cost[index][color]
            );
        }
    }

public:
    long long minCost(
        int n,
        vector<vector<int>>& cost
    ) {
        answer =
            numeric_limits<long long>::max();

        vector<int> colors(
            n
        );

        search(
            cost,
            0,
            colors,
            0
        );

        return answer;
    }
};
