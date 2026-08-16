class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        const int INF =
            1000000000;

        array<int, 4> dp = {
            INF,
            1,
            0,
            1
        };

        for (int position = 1;
             position < static_cast<int>(obstacles.size());
             position++) {
            if (obstacles[position] != 0) {
                dp[obstacles[position]] =
                    INF;
            }

            int best = min({
                dp[1],
                dp[2],
                dp[3]
            });

            for (int lane = 1; lane <= 3; lane++) {
                if (obstacles[position] == lane) {
                    continue;
                }

                dp[lane] = min(
                    dp[lane],
                    best + 1
                );
            }
        }

        return min({
            dp[1],
            dp[2],
            dp[3]
        });
    }
};
