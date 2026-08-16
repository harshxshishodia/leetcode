class Solution {
public:
    int validSubarraySplit(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        const int INF =
            1000000000;

        vector<int> dp(
            n + 1,
            INF
        );

        dp[0] = 0;

        for (int end = 0; end < n; end++) {
            for (int start = 0;
                 start <= end;
                 start++) {
                if (dp[start] == INF) {
                    continue;
                }

                if (gcd(
                        nums[start],
                        nums[end]
                    ) > 1) {
                    dp[end + 1] = min(
                        dp[end + 1],
                        dp[start] + 1
                    );
                }
            }
        }

        return dp[n] == INF
            ? -1
            : dp[n];
    }
};
