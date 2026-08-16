class Solution {
    int solve(const vector<int>& nums, int index, vector<int>& dp) {
        if (index >= static_cast<int>(nums.size()) - 1) {
            return 1;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int furthest = min(
            static_cast<int>(nums.size()) - 1,
            index + nums[index]
        );

        for (int next = index + 1; next <= furthest; next++) {
            if (solve(nums, next, dp)) {
                return dp[index] = 1;
            }
        }

        return dp[index] = 0;
    }

public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};
