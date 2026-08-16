class Solution {
public:
    int maxSumAfterPartitioning(
        vector<int>& arr,
        int k
    ) {
        int n = static_cast<int>(arr.size());

        vector<int> dp(
            k + 1
        );

        for (int end = 1; end <= n; end++) {
            int maximum = 0;
            int best = 0;

            for (int length = 1;
                 length <= k &&
                 length <= end;
                 length++) {
                maximum = max(
                    maximum,
                    arr[end - length]
                );

                best = max(
                    best,
                    dp[(end - length) % (k + 1)] +
                    maximum * length
                );
            }

            dp[end % (k + 1)] = best;
        }

        return dp[n % (k + 1)];
    }
};
