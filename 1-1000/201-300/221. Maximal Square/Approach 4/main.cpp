class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        vector<vector<int>> dp(
            rows + 1,
            vector<int>(cols + 1)
        );

        int bestSide = 0;

        for (int row = 1; row <= rows; row++) {
            for (int col = 1; col <= cols; col++) {
                if (matrix[row - 1][col - 1] == '1') {
                    dp[row][col] = 1 + min({
                        dp[row - 1][col],
                        dp[row][col - 1],
                        dp[row - 1][col - 1]
                    });

                    bestSide = max(bestSide, dp[row][col]);
                }
            }
        }

        return bestSide * bestSide;
    }
};
