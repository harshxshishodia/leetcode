class Solution {
public:
    int minimizeMax(
        vector<int>& nums,
        int p
    ) {
        if (p == 0) {
            return 0;
        }

        sort(
            nums.begin(),
            nums.end()
        );

        int n =
            static_cast<int>(nums.size());

        const int INF =
            numeric_limits<int>::max();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(
                p + 1,
                INF
            )
        );

        for (int index = 0; index <= n; index++) {
            dp[index][0] = 0;
        }

        for (int index = 2; index <= n; index++) {
            for (int pairs = 1;
                 pairs <= p;
                 pairs++) {
                dp[index][pairs] =
                    dp[index - 1][pairs];

                if (dp[index - 2][pairs - 1] != INF) {
                    dp[index][pairs] = min(
                        dp[index][pairs],
                        max(
                            dp[index - 2][pairs - 1],
                            nums[index - 1] -
                            nums[index - 2]
                        )
                    );
                }
            }
        }

        return dp[n][p];
    }
};
