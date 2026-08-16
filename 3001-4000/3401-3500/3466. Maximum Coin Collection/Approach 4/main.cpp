class Solution {
public:
    long long maxCoins(
        vector<int>& lane1,
        vector<int>& lane2
    ) {
        int n =
            static_cast<int>(lane1.size());

        array<array<long long, 3>, 2> next = {};

        long long answer =
            numeric_limits<long long>::min();

        for (int index = n - 1;
             index >= 0;
             index--) {
            array<array<long long, 3>, 2> current = {};

            for (int switches = 0;
                 switches <= 2;
                 switches++) {
                for (int lane = 0;
                     lane <= 1;
                     lane++) {
                    long long value =
                        lane == 0
                            ? lane1[index]
                            : lane2[index];

                    long long best =
                        max(
                            value,
                            value +
                            next[lane][switches]
                        );

                    if (switches > 0) {
                        best = max(
                            best,
                            value +
                            next[lane ^ 1][switches - 1]
                        );

                        best = max(
                            best,
                            current[lane ^ 1][switches - 1]
                        );
                    }

                    current[lane][switches] =
                        best;
                }
            }

            answer = max(
                answer,
                current[0][2]
            );

            next =
                current;
        }

        return answer;
    }
};
