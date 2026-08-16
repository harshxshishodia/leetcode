class Solution {
public:
    int stringCount(int n) {
        const int MOD =
            1000000007;

        long long dp[2][3][2] = {};
        dp[0][0][0] = 1;

        for (int index = 0;
             index < n;
             index++) {
            long long next[2][3][2] = {};

            for (int l = 0;
                 l <= 1;
                 l++) {
                for (int e = 0;
                     e <= 2;
                     e++) {
                    for (int t = 0;
                         t <= 1;
                         t++) {
                        long long ways =
                            dp[l][e][t];

                        if (ways == 0) {
                            continue;
                        }

                        next[l][e][t] =
                            (
                                next[l][e][t] +
                                ways *
                                23
                            ) %
                            MOD;

                        next[1][e][t] =
                            (
                                next[1][e][t] +
                                ways
                            ) %
                            MOD;

                        next[l][min(2, e + 1)][t] =
                            (
                                next[l][min(2, e + 1)][t] +
                                ways
                            ) %
                            MOD;

                        next[l][e][1] =
                            (
                                next[l][e][1] +
                                ways
                            ) %
                            MOD;
                    }
                }
            }

            for (int l = 0;
                 l <= 1;
                 l++) {
                for (int e = 0;
                     e <= 2;
                     e++) {
                    for (int t = 0;
                         t <= 1;
                         t++) {
                        dp[l][e][t] =
                            next[l][e][t];
                    }
                }
            }
        }

        return static_cast<int>(
            dp[1][2][1]
        );
    }
};
