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

        vector<double> dp(
            n + 1
        );

        for (int end = 1; end <= n; end++) {
            dp[end] =
                prefix[end] /
                end;
        }

        for (int groups = 2;
             groups <= k;
             groups++) {
            vector<double> next(
                n + 1
            );

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

                    next[end] = max(
                        next[end],
                        dp[split] +
                        average
                    );
                }
            }

            dp = next;
        }

        return dp[n];
    }
};
