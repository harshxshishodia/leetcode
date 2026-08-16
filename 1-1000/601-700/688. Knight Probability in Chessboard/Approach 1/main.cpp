class Solution {
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

        return probability;
    }

public:
    double knightProbability(
        int n,
        int k,
        int row,
        int column
    ) {
        return solve(
            n,
            k,
            row,
            column
        );
    }
};
