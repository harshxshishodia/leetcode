class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int NEG =
            -1000000000;

        vector<array<int, 3>> dp(
            nums.size() + 1
        );

        dp[0] = {
            0,
            NEG,
            NEG
        };

        for (int index = 1;
             index <= static_cast<int>(nums.size());
             index++) {
            dp[index] =
                dp[index - 1];

            int value =
                nums[index - 1];

            for (int remainder = 0;
                 remainder < 3;
                 remainder++) {
                if (dp[index - 1][remainder] == NEG) {
                    continue;
                }

                int nextRemainder =
                    (
                        remainder +
                        value
                    ) %
                    3;

                dp[index][nextRemainder] = max(
                    dp[index][nextRemainder],
                    dp[index - 1][remainder] +
                    value
                );
            }
        }

        return dp[nums.size()][0];
    }
};
