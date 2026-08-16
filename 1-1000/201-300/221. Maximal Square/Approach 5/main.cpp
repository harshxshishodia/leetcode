class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        vector<int> dp(cols + 1);
        int bestSide = 0;

        for (int row = 1; row <= rows; row++) {
            int diagonal = 0;

            for (int col = 1; col <= cols; col++) {
                int fromTop = dp[col];

                if (matrix[row - 1][col - 1] == '1') {
                    dp[col] = 1 + min({
                        dp[col],
                        dp[col - 1],
                        diagonal
                    });

                    bestSide = max(bestSide, dp[col]);
                } else {
                    dp[col] = 0;
                }

                diagonal = fromTop;
            }
        }

        return bestSide * bestSide;
    }
};
