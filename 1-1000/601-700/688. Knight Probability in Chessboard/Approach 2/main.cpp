class Solution {
    vector<vector<vector<double>>> memo;

    double solve(
        int n,
        int moves,
        int row,
        int col
    ) {
        if (row < 0 ||
            row >= n ||
            col < 0 ||
            col >= n) {
            return 0.0;
        }

        if (moves == 0) {
            return 1.0;
        }

        if (memo[moves][row][col] >= -0.5) {
            return memo[moves][row][col];
        }

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

        double probability = 0.0;

        for (auto [rowChange, colChange] : directions) {
            probability +=
                solve(
                    n,
                    moves - 1,
                    row + rowChange,
                    col + colChange
                ) /
                8.0;
        }

        memo[moves][row][col] = probability;
        return memo[moves][row][col];
    }

public:
    double knightProbability(
        int n,
        int k,
        int row,
        int column
    ) {
        memo.assign(
            k + 1,
            vector<vector<double>>(
                n,
                vector<double>(n, -1.0)
            )
        );

        return solve(
            n,
            k,
            row,
            column
        );
    }
};
