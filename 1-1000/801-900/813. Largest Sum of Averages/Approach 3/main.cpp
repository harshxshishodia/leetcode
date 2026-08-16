class Solution {
public:
    double largestSumOfAverages(
        vector<int>& nums,
        int k
    ) {
        int n = static_cast<int>(nums.size());

        vector<double> prefix(
            n + 1
        );

        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                prefix[i] +
                nums[i];
        }

        vector<vector<double>> dp(
            k + 1,
            vector<double>(
                n + 1
            )
        );

        for (int end = 1; end <= n; end++) {
            dp[1][end] =
                prefix[end] /
                end;
        }

        for (int groups = 2;
             groups <= k;
             groups++) {
            for (int end = groups;
                 end <= n;
                 end++) {
                for (int split = groups - 1;
                     split < end;
                     split++) {
                    double average =
                        (
                            prefix[end] -
                            prefix[split]
                        ) /
                        (end - split);

                    dp[groups][end] = max(
                        dp[groups][end],
                        dp[groups - 1][split] +
                        average
                    );
                }
            }
        }

        return dp[k][n];
    }
};
