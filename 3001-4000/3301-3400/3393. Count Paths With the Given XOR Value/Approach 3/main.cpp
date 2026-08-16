class Solution {
public:
    int countPathsWithXorValue(
        vector<vector<int>>& grid,
        int k
    ) {
        const int MOD =
            1000000007;

        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<vector<array<int, 16>>> dp(
            rows,
            vector<array<int, 16>>(
                cols
            )
        );

        dp[0][0][grid[0][0]] =
            1;

        for (int row = 0;
             row < rows;
             row++) {
            for (int col = 0;
                 col < cols;
                 col++) {
                if (row == 0 &&
                    col == 0) {
                    continue;
                }

                for (int value = 0;
                     value < 16;
                     value++) {
                    int previous =
                        value ^
                        grid[row][col];

                    long long ways = 0;

                    if (row > 0) {
                        ways +=
                            dp[row - 1][col][previous];
                    }

                    if (col > 0) {
                        ways +=
                            dp[row][col - 1][previous];
                    }

                    dp[row][col][value] =
                        static_cast<int>(
                            ways %
                            MOD
                        );
                }
            }
        }

        return
            dp[rows - 1][cols - 1][k];
    }
};
