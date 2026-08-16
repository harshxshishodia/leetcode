class Solution {
public:
    int jump(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> dp(n, 1000000000);
        dp[0] = 0;

        for (int index = 0; index < n; index++) {
            int furthest = min(n - 1, index + nums[index]);

            for (int next = index + 1; next <= furthest; next++) {
                dp[next] = min(dp[next], dp[index] + 1);
            }
        }

        return dp[n - 1];
    }
};
