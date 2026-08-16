class Solution {
    static constexpr int MOD = 1000000007;

    int solve(
        int rows,
        int cols,
        int moves,
        int row,
        int col,
        vector<vector<vector<int>>>& memo
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

        if (memo[moves][row][col] != -1) {
            return memo[moves][row][col];
        }

        long long answer = 0;

        answer += solve(
            rows,
            cols,
            moves - 1,
            row - 1,
            col,
            memo
        );

        answer += solve(
            rows,
            cols,
            moves - 1,
            row + 1,
            col,
            memo
        );

        answer += solve(
            rows,
            cols,
            moves - 1,
            row,
            col - 1,
            memo
        );

        answer += solve(
            rows,
            cols,
            moves - 1,
            row,
            col + 1,
            memo
        );

        memo[moves][row][col] =
            static_cast<int>(answer % MOD);

        return memo[moves][row][col];
    }

public:
    int findPaths(
        int m,
        int n,
        int maxMove,
        int startRow,
        int startColumn
    ) {
        vector<vector<vector<int>>> memo(
            maxMove + 1,
            vector<vector<int>>(
                m,
                vector<int>(n, -1)
            )
        );

        return solve(
            m,
            n,
            maxMove,
            startRow,
            startColumn,
            memo
        );
    }
};
