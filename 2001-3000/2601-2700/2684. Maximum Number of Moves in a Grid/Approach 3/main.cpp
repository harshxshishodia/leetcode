class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<vector<int>> dp(
            rows,
            vector<int>(
                cols
            )
        );

        int answer = 0;

        for (int col = cols - 2;
             col >= 0;
             col--) {
            for (int row = 0;
                 row < rows;
                 row++) {
                for (int nextRow =
                         max(
                             0,
                             row - 1
                         );
                     nextRow <=
                         min(
                             rows - 1,
                             row + 1
                         );
                     nextRow++) {
                    if (grid[nextRow][col + 1] >
                        grid[row][col]) {
                        dp[row][col] = max(
                            dp[row][col],
                            1 +
                            dp[nextRow][col + 1]
                        );
                    }
                }

                if (col == 0) {
                    answer = max(
                        answer,
                        dp[row][col]
                    );
                }
            }
        }

        return answer;
    }
};
