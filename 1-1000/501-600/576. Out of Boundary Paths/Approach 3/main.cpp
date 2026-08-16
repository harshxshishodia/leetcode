class Solution {
public:
    int findPaths(
        int m,
        int n,
        int maxMove,
        int startRow,
        int startColumn
    ) {
        const int MOD = 1000000007;

        vector<vector<vector<int>>> dp(
            maxMove + 1,
            vector<vector<int>>(
                m,
                vector<int>(n)
            )
        );

        dp[0][startRow][startColumn] = 1;
        long long answer = 0;

        array<int, 4> rowChange = {-1, 1, 0, 0};
        array<int, 4> colChange = {0, 0, -1, 1};

        for (int move = 0; move < maxMove; move++) {
            for (int row = 0; row < m; row++) {
                for (int col = 0; col < n; col++) {
                    int ways = dp[move][row][col];

                    if (ways == 0) {
                        continue;
                    }

                    for (int direction = 0; direction < 4; direction++) {
                        int nextRow = row + rowChange[direction];
                        int nextCol = col + colChange[direction];

                        if (nextRow < 0 ||
                            nextRow >= m ||
                            nextCol < 0 ||
                            nextCol >= n) {
                            answer = (answer + ways) % MOD;
                        } else {
                            dp[move + 1][nextRow][nextCol] =
                                (dp[move + 1][nextRow][nextCol] + ways) % MOD;
                        }
                    }
                }
            }
        }

        return static_cast<int>(answer);
    }
};
