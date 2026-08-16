class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        vector<array<long long, 2>> dp(
            n + 1
        );

        for (int index = n - 1; index >= 0; index--) {
            dp[index][0] = max(
                dp[index + 1][0],
                nums[index] +
                dp[index + 1][1]
            );

            dp[index][1] = max(
                dp[index + 1][1],
                -nums[index] +
                dp[index + 1][0]
            );
        }

        return dp[0][0];
    }
};
