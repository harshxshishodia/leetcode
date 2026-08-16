class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n =
            static_cast<int>(arr.size());

        vector<vector<int>> maximumValue(
            n,
            vector<int>(n)
        );

        for (int left = 0; left < n; left++) {
            int maximum = 0;

            for (int right = left;
                 right < n;
                 right++) {
                maximum = max(
                    maximum,
                    arr[right]
                );

                maximumValue[left][right] =
                    maximum;
            }
        }

        vector<vector<int>> dp(
            n,
            vector<int>(n)
        );

        for (int length = 2; length <= n; length++) {
            for (int left = 0;
                 left + length <= n;
                 left++) {
                int right =
                    left + length - 1;

                dp[left][right] =
                    numeric_limits<int>::max();

                for (int split = left;
                     split < right;
                     split++) {
                    dp[left][right] = min(
                        dp[left][right],
                        dp[left][split] +
                        dp[split + 1][right] +
                        maximumValue[left][split] *
                        maximumValue[split + 1][right]
                    );
                }
            }
        }

        return dp[0][n - 1];
    }
};
