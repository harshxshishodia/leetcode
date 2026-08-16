class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int rows =
            static_cast<int>(coins.size());

        int cols =
            static_cast<int>(coins[0].size());

        const int NEG =
            numeric_limits<int>::min() /
            4;

        vector<array<int, 3>> previous(
            cols,
            array<int, 3>{
                NEG,
                NEG,
                NEG
            }
        );

        for (int row = 0;
             row < rows;
             row++) {
            vector<array<int, 3>> current(
                cols,
                array<int, 3>{
                    NEG,
                    NEG,
                    NEG
                }
            );

            for (int col = 0;
                 col < cols;
                 col++) {
                if (row == 0 &&
                    col == 0) {
                    current[col][0] =
                        coins[0][0];

                    if (coins[0][0] < 0) {
                        current[col][1] =
                            0;
                    }

                    continue;
                }

                for (int used = 0;
                     used <= 2;
                     used++) {
                    int best =
                        NEG;

                    if (row > 0) {
                        best = max(
                            best,
                            previous[col][used]
                        );
                    }

                    if (col > 0) {
                        best = max(
                            best,
                            current[col - 1][used]
                        );
                    }

                    if (best != NEG) {
                        current[col][used] = max(
                            current[col][used],
                            best +
                            coins[row][col]
                        );
                    }

                    if (
                        coins[row][col] < 0 &&
                        used > 0
                    ) {
                        int before =
                            NEG;

                        if (row > 0) {
                            before = max(
                                before,
                                previous[col][used - 1]
                            );
                        }

                        if (col > 0) {
                            before = max(
                                before,
                                current[col - 1][used - 1]
                            );
                        }

                        current[col][used] = max(
                            current[col][used],
                            before
                        );
                    }
                }
            }

            previous.swap(
                current
            );
        }

        return max({
            previous[cols - 1][0],
            previous[cols - 1][1],
            previous[cols - 1][2]
        });
    }
};
