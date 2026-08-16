class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(
            nums.begin(),
            nums.end(),
            0
        );

        if (abs(target) > total) {
            return 0;
        }

        int offset = total;
        vector<int> dp(2 * total + 1);
        dp[offset] = 1;

        for (int number : nums) {
            vector<int> next(2 * total + 1);

            for (int sum = -total; sum <= total; sum++) {
                int ways = dp[sum + offset];

                if (ways == 0) {
                    continue;
                }

                next[sum + number + offset] += ways;
                next[sum - number + offset] += ways;
            }

            dp = next;
        }

        return dp[target + offset];
    }
};
