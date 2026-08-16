class Solution {
public:
    int lengthOfLongestSubsequence(
        vector<int>& nums,
        int target
    ) {
        const int NEG =
            -1000000000;

        int n =
            static_cast<int>(nums.size());

        vector<vector<int>> dp(
            n + 1,
            vector<int>(
                target + 1,
                NEG
            )
        );

        dp[0][0] = 0;

        for (int index = 1;
             index <= n;
             index++) {
            for (int sum = 0;
                 sum <= target;
                 sum++) {
                dp[index][sum] =
                    dp[index - 1][sum];

                if (
                    sum >= nums[index - 1] &&
                    dp[index - 1][
                        sum -
                        nums[index - 1]
                    ] != NEG
                ) {
                    dp[index][sum] = max(
                        dp[index][sum],
                        1 +
                        dp[index - 1][
                            sum -
                            nums[index - 1]
                        ]
                    );
                }
            }
        }

        return dp[n][target] < 0
            ? -1
            : dp[n][target];
    }
};
