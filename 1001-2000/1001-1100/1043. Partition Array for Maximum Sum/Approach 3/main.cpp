class Solution {
public:
    int maxSumAfterPartitioning(
        vector<int>& arr,
        int k
    ) {
        int n = static_cast<int>(arr.size());

        vector<int> dp(
            n + 1
        );

        for (int end = 1; end <= n; end++) {
            int maximum = 0;

            for (int length = 1;
                 length <= k &&
                 length <= end;
                 length++) {
                maximum = max(
                    maximum,
                    arr[end - length]
                );

                dp[end] = max(
                    dp[end],
                    dp[end - length] +
                    maximum * length
                );
            }
        }

        return dp[n];
    }
};
