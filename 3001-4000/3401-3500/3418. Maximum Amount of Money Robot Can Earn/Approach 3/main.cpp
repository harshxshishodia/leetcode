class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int rows =
            static_cast<int>(coins.size());

        int cols =
            static_cast<int>(coins[0].size());

        const int NEG =
            numeric_limits<int>::min() /
            4;

        vector<vector<array<int, 3>>> dp(
            rows,
            vector<array<int, 3>>(
                cols,
                array<int, 3>{
                    NEG,
                    NEG,
                    NEG
                }
            )
        );

        dp[0][0][0] =
            coins[0][0];

        if (coins[0][0] < 0) {
            dp[0][0][1] =
                0;
        }

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

                for (int used = 0;
                     used <= 2;
                     used++) {
                    int best =
                        NEG;

                    if (row > 0) {
                        best = max(
                            best,
                            dp[row - 1][col][used]
                        );
                    }

                    if (col > 0) {
                        best = max(
                            best,
                            dp[row][col - 1][used]
                        );
                    }

                    if (best != NEG) {
                        dp[row][col][used] = max(
                            dp[row][col][used],
                            best +
                            coins[row][col]
                        );
                    }

                    if (
                        coins[row][col] < 0 &&
                        used > 0
                    ) {
                        int before =
                            NEG;

                        if (row > 0) {
                            before = max(
                                before,
                                dp[row - 1][col][used - 1]
                            );
                        }

                        if (col > 0) {
                            before = max(
                                before,
                                dp[row][col - 1][used - 1]
                            );
                        }

                        dp[row][col][used] = max(
                            dp[row][col][used],
                            before
                        );
                    }
                }
            }
        }

        return max({
            dp[rows - 1][cols - 1][0],
            dp[rows - 1][cols - 1][1],
            dp[rows - 1][cols - 1][2]
        });
    }
};
