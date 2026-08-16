class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(
            nums.begin(),
            nums.end(),
            0
        );

        if (abs(target) > total ||
            (total + target) % 2 != 0) {
            return 0;
        }

        int subset = (total + target) / 2;

        if (subset < 0) {
            return 0;
        }

        vector<int> dp(subset + 1);
        dp[0] = 1;

        for (int number : nums) {
            for (int sum = subset; sum >= number; sum--) {
                dp[sum] += dp[sum - number];
            }
        }

        return dp[subset];
    }
};
