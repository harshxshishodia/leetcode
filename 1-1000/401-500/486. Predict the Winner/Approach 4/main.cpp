class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> dp = nums;

        for (int length = 2; length <= n; length++) {
            for (int left = 0;
                 left + length <= n;
                 left++) {
                int right = left + length - 1;

                dp[left] = max(
                    nums[left] - dp[left + 1],
                    nums[right] - dp[left]
                );
            }
        }

        return dp[0] >= 0;
    }
};
