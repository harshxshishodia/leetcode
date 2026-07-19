class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int index = 0; index < n; index++) {
            for (int jumpLength = 1; jumpLength <= nums[index] && index + jumpLength < n; jumpLength++)
                dp[index + jumpLength] = min(dp[index + jumpLength], dp[index] + 1);
        }

        return dp[n - 1];
    }
};