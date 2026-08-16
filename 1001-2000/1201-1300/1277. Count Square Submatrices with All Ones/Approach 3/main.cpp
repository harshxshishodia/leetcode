class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());

        vector<vector<int>> dp(
            rows,
            vector<int>(cols)
        );

        int answer = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) {
                    continue;
                }

                dp[row][col] = 1;

                if (row > 0 && col > 0) {
                    dp[row][col] += min({
                        dp[row - 1][col],
                        dp[row][col - 1],
                        dp[row - 1][col - 1]
                    });
                }

                answer += dp[row][col];
            }
        }

        return answer;
    }
};
