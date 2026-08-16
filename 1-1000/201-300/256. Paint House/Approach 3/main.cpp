class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }

        int n = static_cast<int>(costs.size());
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0] = costs[0];

        for (int house = 1; house < n; house++) {
            dp[house][0] = costs[house][0] +
                           min(dp[house - 1][1], dp[house - 1][2]);

            dp[house][1] = costs[house][1] +
                           min(dp[house - 1][0], dp[house - 1][2]);

            dp[house][2] = costs[house][2] +
                           min(dp[house - 1][0], dp[house - 1][1]);
        }

        return min({
            dp[n - 1][0],
            dp[n - 1][1],
            dp[n - 1][2]
        });
    }
};
