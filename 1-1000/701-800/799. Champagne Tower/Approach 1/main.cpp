class Solution {
    double amount(
        int poured,
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

        double fromLeft =
            max(
                0.0,
                (amount(
                    poured,
                    row - 1,
                    glass - 1
                ) - 1.0) /
                2.0
            );

        double fromRight =
            max(
                0.0,
                (amount(
                    poured,
                    row - 1,
                    glass
                ) - 1.0) /
                2.0
            );

        return
            fromLeft +
            fromRight;
    }

public:
    double champagneTower(
        int poured,
        int query_row,
        int query_glass
    ) {
        return min(
            1.0,
            amount(
                poured,
                query_row,
                query_glass
            )
        );
    }
};
