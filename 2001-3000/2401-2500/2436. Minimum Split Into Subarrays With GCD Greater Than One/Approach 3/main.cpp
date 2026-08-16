class Solution {
public:
    int minimumSplits(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        const int INF =
            1000000000;

        vector<int> dp(
            n + 1,
            INF
        );

        dp[0] = 0;

        for (int start = 0; start < n; start++) {
            if (dp[start] == INF) {
                continue;
            }

            int currentGcd = 0;

            for (int end = start; end < n; end++) {
                currentGcd =
                    gcd(
                        currentGcd,
                        nums[end]
                    );

                if (currentGcd > 1) {
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
