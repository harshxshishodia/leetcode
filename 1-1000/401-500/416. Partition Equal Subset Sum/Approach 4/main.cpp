class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0) {
            return false;
        }

        int target = total / 2;
        vector<bool> dp(target + 1);
        dp[0] = true;

        for (int number : nums) {
            for (int sum = target; sum >= number; sum--) {
                dp[sum] = dp[sum] || dp[sum - number];
            }
        }

        return dp[target];
    }
};
