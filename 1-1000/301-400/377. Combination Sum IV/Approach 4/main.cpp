class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1);
        dp[0] = 1;

        for (int sum = 1; sum <= target; sum++) {
            for (int number : nums) {
                if (number <= sum) {
                    dp[sum] += dp[sum - number];
                }
            }
        }

        return static_cast<int>(dp[target]);
    }
};
