class Solution {
public:
    int minSpaceWastedKResizing(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(nums.size());

        int segments = min(
            n,
            k + 1
        );

        vector<vector<int>> waste(
            n,
            vector<int>(n)
        );

        for (int left = 0; left < n; left++) {
            int maximum = 0;
            int sum = 0;

            for (int right = left; right < n; right++) {
                maximum = max(
                    maximum,
                    nums[right]
                );

                sum +=
                    nums[right];

                waste[left][right] =
                    maximum *
                    (right - left + 1) -
                    sum;
            }
        }

        const int INF =
            1000000000;

        vector<vector<int>> dp(
            segments + 1,
            vector<int>(
                n + 1,
                INF
            )
        );

        dp[0][0] = 0;

        for (int groups = 1;
             groups <= segments;
             groups++) {
            for (int end = 1; end <= n; end++) {
                for (int start = groups - 1;
                     start < end;
                     start++) {
                    if (dp[groups - 1][start] == INF) {
                        continue;
                    }

                    dp[groups][end] = min(
                        dp[groups][end],
                        dp[groups - 1][start] +
                        waste[start][end - 1]
                    );
                }
            }
        }

        return dp[segments][n];
    }
};
