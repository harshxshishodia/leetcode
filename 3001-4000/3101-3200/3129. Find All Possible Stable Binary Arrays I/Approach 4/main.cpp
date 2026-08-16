class Solution {
public:
    int numberOfStableArrays(
        int zero,
        int one,
        int limit
    ) {
        const int MOD =
            1000000007;

        vector<vector<int>> endZero(
            zero + 1,
            vector<int>(
                one + 1
            )
        );

        vector<vector<int>> endOne(
            zero + 1,
            vector<int>(
                one + 1
            )
        );

        for (int z = 1;
             z <= min(
                 zero,
                 limit
             );
             z++) {
            endZero[z][0] =
                1;
        }

        for (int o = 1;
             o <= min(
                 one,
                 limit
             );
             o++) {
            endOne[0][o] =
                1;
        }

        for (int z = 1;
             z <= zero;
             z++) {
            for (int o = 1;
                 o <= one;
                 o++) {
                long long zeroWays =
                    endZero[z - 1][o] +
                    endOne[z - 1][o];

                if (z - limit - 1 >= 0) {
                    zeroWays -=
                        endOne[
                            z -
                            limit -
                            1
                        ][o];
                }

                zeroWays %=
                    MOD;

                if (zeroWays < 0) {
                    zeroWays +=
                        MOD;
                }

                endZero[z][o] =
                    static_cast<int>(
                        zeroWays
                    );

                long long oneWays =
                    endZero[z][o - 1] +
                    endOne[z][o - 1];

                if (o - limit - 1 >= 0) {
                    oneWays -=
                        endZero[
                            z
                        ][
                            o -
                            limit -
                            1
                        ];
                }

                oneWays %=
                    MOD;

                if (oneWays < 0) {
                    oneWays +=
                        MOD;
                }

                endOne[z][o] =
                    static_cast<int>(
                        oneWays
                    );
            }
        }

        return
            (
                endZero[zero][one] +
                endOne[zero][one]
            ) %
            MOD;
    }
};
