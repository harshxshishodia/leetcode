class Solution {
public:
    int lengthOfLongestSubsequence(
        vector<int>& nums,
        int target
    ) {
        const int NEG =
            -1000000000;

        vector<int> dp(
            target + 1,
            NEG
        );

        dp[0] = 0;

        for (int value : nums) {
            for (int sum = target;
                 sum >= value;
                 sum--) {
                if (dp[sum - value] == NEG) {
                    continue;
                }

                dp[sum] = max(
                    dp[sum],
                    1 +
                    dp[sum - value]
                );
            }
        }

        return dp[target] < 0
            ? -1
            : dp[target];
    }
};
