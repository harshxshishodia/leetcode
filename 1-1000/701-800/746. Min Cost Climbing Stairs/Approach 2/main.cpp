class Solution {
    int solve(vector<int>& cost, int index, vector<int>& dp) {
        if (index >= static_cast<int>(cost.size())) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        dp[index] = cost[index] + min(
            solve(cost, index + 1, dp),
            solve(cost, index + 2, dp)
        );

        return dp[index];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }
};
