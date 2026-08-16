class Solution {
    vector<vector<double>> memo;
    vector<vector<bool>> visited;
    int poured;

    double amount(
        int row,
        int glass
    ) {
        if (glass < 0 ||
            glass > row) {
            return 0.0;
        }

        if (row == 0) {
            return glass == 0
                ? poured
                : 0.0;
        }

        if (visited[row][glass]) {
            return memo[row][glass];
        }

        visited[row][glass] = true;

        double fromLeft =
            max(
                0.0,
                (amount(
                    row - 1,
                    glass - 1
                ) - 1.0) /
                2.0
            );

        double fromRight =
            max(
                0.0,
                (amount(
                    row - 1,
                    glass
                ) - 1.0) /
                2.0
            );

        memo[row][glass] =
            fromLeft +
            fromRight;

        return memo[row][glass];
    }

public:
    double champagneTower(
        int input,
        int query_row,
        int query_glass
    ) {
        poured = input;

        memo.assign(
            query_row + 1,
            vector<double>(
                query_row + 1
            )
        );

        visited.assign(
            query_row + 1,
            vector<bool>(
                query_row + 1
            )
        );

        return min(
            1.0,
            amount(
                query_row,
                query_glass
            )
        );
    }
};
