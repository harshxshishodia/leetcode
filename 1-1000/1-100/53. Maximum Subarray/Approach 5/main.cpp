class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> dp(n);
        dp[0] = nums[0];
        int answer = dp[0];

        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
            answer = max(answer, dp[i]);
        }

        return answer;
    }
};
