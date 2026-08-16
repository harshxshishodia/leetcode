class Solution {
public:
    double champagneTower(
        int poured,
        int query_row,
        int query_glass
    ) {
        vector<double> row(
            query_row + 2
        );

        row[0] = poured;

        for (int currentRow = 0;
             currentRow < query_row;
             currentRow++) {
            for (int glass = currentRow;
                 glass >= 0;
                 glass--) {
                double overflow =
                    max(
                        0.0,
                        (row[glass] - 1.0) /
                        2.0
                    );

                row[glass + 1] +=
                    overflow;

                row[glass] =
                    overflow;
            }
        }

        return min(
            1.0,
            row[query_glass]
        );
    }
};
