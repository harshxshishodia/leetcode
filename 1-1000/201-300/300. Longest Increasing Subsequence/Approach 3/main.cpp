class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<vector<int>> dp(
            n + 1,
            vector<int>(n + 1)
        );

        for (int index = n - 1; index >= 0; index--) {
            for (int previousIndex = index - 1;
                 previousIndex >= -1;
                 previousIndex--) {
                int skip = dp[index + 1][previousIndex + 1];
                int take = 0;

                if (previousIndex == -1 ||
                    nums[index] > nums[previousIndex]) {
                    take = 1 + dp[index + 1][index + 1];
                }

                dp[index][previousIndex + 1] = max(skip, take);
            }
        }

        return dp[0][0];
    }
};
