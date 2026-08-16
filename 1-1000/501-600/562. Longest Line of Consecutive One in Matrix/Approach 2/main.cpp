class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return 0;
        }

        int rows = static_cast<int>(mat.size());
        int cols = static_cast<int>(mat[0].size());

        vector<vector<array<int, 4>>> dp(
            rows,
            vector<array<int, 4>>(cols)
        );

        int answer = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (mat[row][col] == 0) {
                    continue;
                }

                dp[row][col][0] =
                    1 + (col > 0 ? dp[row][col - 1][0] : 0);

                dp[row][col][1] =
                    1 + (row > 0 ? dp[row - 1][col][1] : 0);

                dp[row][col][2] =
                    1 + (
                        row > 0 && col > 0
                            ? dp[row - 1][col - 1][2]
                            : 0
                    );

                dp[row][col][3] =
                    1 + (
                        row > 0 && col + 1 < cols
                            ? dp[row - 1][col + 1][3]
                            : 0
                    );

                answer = max({
                    answer,
                    dp[row][col][0],
                    dp[row][col][1],
                    dp[row][col][2],
                    dp[row][col][3]
                });
            }
        }

        return answer;
    }
};
