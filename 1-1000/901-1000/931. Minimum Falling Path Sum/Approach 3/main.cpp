class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = static_cast<int>(matrix.size());

        vector<vector<int>> dp = matrix;

        for (int row = 1; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int best =
                    dp[row - 1][col];

                if (col > 0) {
                    best = min(
                        best,
                        dp[row - 1][col - 1]
                    );
                }

                if (col + 1 < n) {
                    best = min(
                        best,
                        dp[row - 1][col + 1]
                    );
                }

                dp[row][col] += best;
            }
        }

        return *min_element(
            dp[n - 1].begin(),
            dp[n - 1].end()
        );
    }
};
