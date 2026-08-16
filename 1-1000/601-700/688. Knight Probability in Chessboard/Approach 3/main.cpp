class Solution {
public:
    double knightProbability(
        int n,
        int k,
        int row,
        int column
    ) {
        static const array<pair<int, int>, 8> directions = {{
            {-2, -1},
            {-2, 1},
            {-1, -2},
            {-1, 2},
            {1, -2},
            {1, 2},
            {2, -1},
            {2, 1}
        }};

        vector<vector<vector<double>>> dp(
            k + 1,
            vector<vector<double>>(
                n,
                vector<double>(n)
            )
        );

        dp[0][row][column] = 1.0;

        for (int move = 0; move < k; move++) {
            for (int currentRow = 0; currentRow < n; currentRow++) {
                for (int currentCol = 0; currentCol < n; currentCol++) {
                    double probability =
                        dp[move][currentRow][currentCol];

                    if (probability == 0.0) {
                        continue;
                    }

                    for (auto [rowChange, colChange] : directions) {
                        int nextRow =
                            currentRow + rowChange;

                        int nextCol =
                            currentCol + colChange;

                        if (nextRow < 0 ||
                            nextRow >= n ||
                            nextCol < 0 ||
                            nextCol >= n) {
                            continue;
                        }

                        dp[move + 1][nextRow][nextCol] +=
                            probability / 8.0;
                    }
                }
            }
        }

        double answer = 0.0;

        for (int currentRow = 0; currentRow < n; currentRow++) {
            for (int currentCol = 0; currentCol < n; currentCol++) {
                answer += dp[k][currentRow][currentCol];
            }
        }

        return answer;
    }
};
