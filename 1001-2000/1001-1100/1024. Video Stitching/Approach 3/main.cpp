class Solution {
public:
    int videoStitching(
        vector<vector<int>>& clips,
        int time
    ) {
        const int INF = 1000000000;

        vector<int> dp(
            time + 1,
            INF
        );

        dp[0] = 0;

        for (int covered = 0; covered < time; covered++) {
            if (dp[covered] == INF) {
                continue;
            }

            for (const vector<int>& clip : clips) {
                if (clip[0] > covered ||
                    clip[1] <= covered) {
                    continue;
                }

                int next =
                    min(
                        time,
                        clip[1]
                    );

                dp[next] = min(
                    dp[next],
                    dp[covered] + 1
                );
            }
        }

        return dp[time] == INF
            ? -1
            : dp[time];
    }
};
