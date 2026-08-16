class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());

        vector<int> dp(cols + 1);
        int answer = 0;

        for (int row = 0; row < rows; row++) {
            int diagonal = 0;

            for (int col = 1; col <= cols; col++) {
                int previous = dp[col];

                if (matrix[row][col - 1] == 1) {
                    dp[col] = 1 + min({
                        dp[col],
                        dp[col - 1],
                        diagonal
                    });

                    answer += dp[col];
                } else {
                    dp[col] = 0;
                }

                diagonal = previous;
            }
        }

        return answer;
    }
};
