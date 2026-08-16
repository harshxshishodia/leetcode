class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n =
            static_cast<int>(obstacles.size());

        const int INF =
            1000000000;

        vector<array<int, 4>> dp(n);

        dp[0] = {
            INF,
            1,
            0,
            1
        };

        for (int position = 1;
             position < n;
             position++) {
            dp[position] =
                dp[position - 1];

            if (obstacles[position] != 0) {
                dp[position][obstacles[position]] =
                    INF;
            }

            int best = min({
                dp[position][1],
                dp[position][2],
                dp[position][3]
            });

            for (int lane = 1; lane <= 3; lane++) {
                if (obstacles[position] == lane) {
                    continue;
                }

                dp[position][lane] = min(
                    dp[position][lane],
                    best + 1
                );
            }
        }

        return min({
            dp[n - 1][1],
            dp[n - 1][2],
            dp[n - 1][3]
        });
    }
};
