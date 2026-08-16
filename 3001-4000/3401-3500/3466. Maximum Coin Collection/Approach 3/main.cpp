class Solution {
public:
    long long maxCoins(
        vector<int>& lane1,
        vector<int>& lane2
    ) {
        int n =
            static_cast<int>(lane1.size());

        vector<vector<array<long long, 3>>> dp(
            n + 1,
            vector<array<long long, 3>>(
                2
            )
        );

        long long answer =
            numeric_limits<long long>::min();

        for (int index = n - 1;
             index >= 0;
             index--) {
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
                            dp[index + 1][lane][switches]
                        );

                    if (switches > 0) {
                        best = max(
                            best,
                            value +
                            dp[index + 1][lane ^ 1][switches - 1]
                        );

                        best = max(
                            best,
                            dp[index][lane ^ 1][switches - 1]
                        );
                    }

                    dp[index][lane][switches] =
                        best;
                }
            }

            answer = max(
                answer,
                dp[index][0][2]
            );
        }

        return answer;
    }
};
