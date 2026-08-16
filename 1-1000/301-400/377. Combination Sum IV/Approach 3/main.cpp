class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int minimum = *min_element(nums.begin(), nums.end());
        int maximumLength = target / minimum;

        vector<vector<unsigned long long>> dp(
            maximumLength + 1,
            vector<unsigned long long>(target + 1)
        );

        dp[0][0] = 1;
        unsigned long long answer = 0;

        for (int length = 1; length <= maximumLength; length++) {
            for (int sum = 1; sum <= target; sum++) {
                for (int number : nums) {
                    if (number <= sum) {
                        dp[length][sum] +=
                            dp[length - 1][sum - number];
                    }
                }
            }

            answer += dp[length][target];
        }

        return static_cast<int>(answer);
    }
};
