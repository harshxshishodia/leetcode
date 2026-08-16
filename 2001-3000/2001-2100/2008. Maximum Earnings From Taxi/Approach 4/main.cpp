class Solution {
public:
    long long maxTaxiEarnings(
        int n,
        vector<vector<int>>& rides
    ) {
        vector<vector<pair<int, int>>> ending(
            n + 1
        );

        for (const vector<int>& ride : rides) {
            ending[ride[1]].push_back({
                ride[0],
                ride[2]
            });
        }

        vector<long long> dp(
            n + 1
        );

        for (int point = 1; point <= n; point++) {
            dp[point] =
                dp[point - 1];

            for (auto [start, tip] : ending[point]) {
                dp[point] = max(
                    dp[point],
                    dp[start] +
                    point -
                    start +
                    tip
                );
            }
        }

        return dp[n];
    }
};
