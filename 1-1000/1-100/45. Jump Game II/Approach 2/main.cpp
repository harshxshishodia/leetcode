class Solution {
    int solve(const vector<int>& nums, int index, vector<int>& dp) {
        int n = static_cast<int>(nums.size());

        if (index >= n - 1) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int answer = 1000000000;
        int furthest = min(n - 1, index + nums[index]);

        for (int next = index + 1; next <= furthest; next++) {
            answer = min(answer, 1 + solve(nums, next, dp));
        }

        dp[index] = answer;
        return dp[index];
    }

public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};
