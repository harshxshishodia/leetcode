class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = static_cast<int>(values.size());

        vector<vector<int>> dp(
            n,
            vector<int>(n)
        );

        for (int length = 3; length <= n; length++) {
            for (int left = 0;
                 left + length <= n;
                 left++) {
                int right =
                    left + length - 1;

                dp[left][right] =
                    numeric_limits<int>::max();

                for (int middle = left + 1;
                     middle < right;
                     middle++) {
                    dp[left][right] = min(
                        dp[left][right],
                        values[left] *
                        values[middle] *
                        values[right] +
                        dp[left][middle] +
                        dp[middle][right]
                    );
                }
            }
        }

        return dp[0][n - 1];
    }
};
