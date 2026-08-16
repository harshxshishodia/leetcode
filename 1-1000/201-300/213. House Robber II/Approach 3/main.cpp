class Solution {
    int robRange(const vector<int>& nums, int left, int right) {
        int length = right - left + 1;
        vector<int> dp(length + 1);
        dp[1] = nums[left];

        for (int i = 2; i <= length; i++) {
            dp[i] = max(
                dp[i - 1],
                dp[i - 2] + nums[left + i - 1]
            );
        }

        return dp[length];
    }

public:
    int rob(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        if (n == 1) {
            return nums[0];
        }

        return max(
            robRange(nums, 0, n - 2),
            robRange(nums, 1, n - 1)
        );
    }
};
