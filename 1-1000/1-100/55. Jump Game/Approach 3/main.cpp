class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<bool> dp(n);
        dp[n - 1] = true;

        for (int index = n - 2; index >= 0; index--) {
            int furthest = min(n - 1, index + nums[index]);

            for (int next = index + 1; next <= furthest; next++) {
                if (dp[next]) {
                    dp[index] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
