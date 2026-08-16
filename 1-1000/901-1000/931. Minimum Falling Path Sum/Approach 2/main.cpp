class Solution {
    int solve(
        const vector<vector<int>>& matrix,
        int row,
        int col,
        vector<vector<int>>& memo
    ) {
        int n = static_cast<int>(matrix.size());

        if (col < 0 || col >= n) {
            return 1000000000;
        }

        if (row == n - 1) {
            return matrix[row][col];
        }

        if (memo[row][col] != 1000000001) {
            return memo[row][col];
        }

        memo[row][col] =
            matrix[row][col] +
            min({
                solve(
                    matrix,
                    row + 1,
                    col - 1,
                    memo
                ),
                solve(
                    matrix,
                    row + 1,
                    col,
                    memo
                ),
                solve(
                    matrix,
                    row + 1,
                    col + 1,
                    memo
                )
            });

        return memo[row][col];
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = static_cast<int>(matrix.size());

        vector<vector<int>> memo(
            n,
            vector<int>(
                n,
                1000000001
            )
        );

        int answer =
            numeric_limits<int>::max();

        for (int col = 0; col < n; col++) {
            answer = min(
                answer,
                solve(
                    matrix,
                    0,
                    col,
                    memo
                )
            );
        }

        return answer;
    }
};
