class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0) {
            return false;
        }

        int target = total / 2;
        int n = static_cast<int>(nums.size());
        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(target + 1)
        );

        for (int index = 0; index <= n; index++) {
            dp[index][0] = true;
        }

        for (int index = 1; index <= n; index++) {
            for (int sum = 1; sum <= target; sum++) {
                dp[index][sum] = dp[index - 1][sum];

                if (nums[index - 1] <= sum) {
                    dp[index][sum] =
                        dp[index][sum] ||
                        dp[index - 1][sum - nums[index - 1]];
                }
            }
        }

        return dp[n][target];
    }
};
