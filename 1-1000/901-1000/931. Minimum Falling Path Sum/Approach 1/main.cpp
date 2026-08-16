class Solution {
    int solve(
        const vector<vector<int>>& matrix,
        int row,
        int col
    ) {
        int n = static_cast<int>(matrix.size());

        if (col < 0 || col >= n) {
            return 1000000000;
        }

        if (row == n - 1) {
            return matrix[row][col];
        }

        return matrix[row][col] + min({
            solve(
                matrix,
                row + 1,
                col - 1
            ),
            solve(
                matrix,
                row + 1,
                col
            ),
            solve(
                matrix,
                row + 1,
                col + 1
            )
        });
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int answer =
            numeric_limits<int>::max();

        for (int col = 0;
             col < static_cast<int>(matrix.size());
             col++) {
            answer = min(
                answer,
                solve(
                    matrix,
                    0,
                    col
                )
            );
        }

        return answer;
    }
};
