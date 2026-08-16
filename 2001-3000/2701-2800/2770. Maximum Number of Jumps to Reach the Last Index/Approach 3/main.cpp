class Solution {
public:
    int maximumJumps(
        vector<int>& nums,
        int target
    ) {
        int n =
            static_cast<int>(nums.size());

        const int NEG =
            -1000000000;

        vector<int> dp(
            n,
            NEG
        );

        dp[0] = 0;

        for (int index = 1;
             index < n;
             index++) {
            for (int previous = 0;
                 previous < index;
                 previous++) {
                if (dp[previous] == NEG) {
                    continue;
                }

                if (abs(
                        nums[index] -
                        nums[previous]
                    ) <= target) {
                    dp[index] = max(
                        dp[index],
                        dp[previous] + 1
                    );
                }
            }
        }

        return dp[n - 1] < 0
            ? -1
            : dp[n - 1];
    }
};
