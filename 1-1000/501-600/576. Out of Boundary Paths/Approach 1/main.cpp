class Solution {
    static constexpr int MOD = 1000000007;

    int solve(
        int rows,
        int cols,
        int moves,
        int row,
        int col
    ) {
        if (row < 0 ||
            row >= rows ||
            col < 0 ||
            col >= cols) {
            return 1;
        }

        if (moves == 0) {
            return 0;
        }

        long long answer = 0;

        answer += solve(rows, cols, moves - 1, row - 1, col);
        answer += solve(rows, cols, moves - 1, row + 1, col);
        answer += solve(rows, cols, moves - 1, row, col - 1);
        answer += solve(rows, cols, moves - 1, row, col + 1);

        return static_cast<int>(answer % MOD);
    }

public:
    int findPaths(
        int m,
        int n,
        int maxMove,
        int startRow,
        int startColumn
    ) {
        return solve(
            m,
            n,
            maxMove,
            startRow,
            startColumn
        );
    }
};
