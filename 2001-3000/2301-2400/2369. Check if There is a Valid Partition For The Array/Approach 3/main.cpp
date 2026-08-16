class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        vector<bool> dp(
            n + 1
        );

        dp[0] = true;

        for (int length = 2;
             length <= n;
             length++) {
            if (dp[length - 2] &&
                nums[length - 2] ==
                nums[length - 1]) {
                dp[length] = true;
            }

            if (length >= 3 &&
                dp[length - 3]) {
                bool tripleEqual =
                    nums[length - 3] ==
                        nums[length - 2] &&
                    nums[length - 2] ==
                        nums[length - 1];

                bool consecutive =
                    nums[length - 3] + 1 ==
                        nums[length - 2] &&
                    nums[length - 2] + 1 ==
                        nums[length - 1];

                dp[length] =
                    dp[length] ||
                    tripleEqual ||
                    consecutive;
            }
        }

        return dp[n];
    }
};
