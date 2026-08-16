class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        for (int length = 2; length <= n; length++) {
            for (int left = 0;
                 left + length <= n;
                 left++) {
                int right = left + length - 1;

                dp[left][right] = max(
                    nums[left] - dp[left + 1][right],
                    nums[right] - dp[left][right - 1]
                );
            }
        }

        return dp[0][n - 1] >= 0;
    }
};
