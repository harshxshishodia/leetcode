class Solution {
public:
    int distributeCookies(
        vector<int>& cookies,
        int k
    ) {
        int n =
            static_cast<int>(cookies.size());

        int states =
            1 << n;

        vector<int> sum(states);

        for (int mask = 1; mask < states; mask++) {
            int bit =
                __builtin_ctz(
                    static_cast<unsigned int>(mask)
                );

            sum[mask] =
                sum[
                    mask &
                    (mask - 1)
                ] +
                cookies[bit];
        }

        const int INF =
            numeric_limits<int>::max();

        vector<vector<int>> dp(
            k + 1,
            vector<int>(
                states,
                INF
            )
        );

        dp[0][0] = 0;

        for (int children = 1;
             children <= k;
             children++) {
            for (int mask = 0; mask < states; mask++) {
                for (int submask = mask;
                     ;
                     submask =
                     (submask - 1) & mask) {
                    if (dp[children - 1][
                            mask ^ submask
                        ] != INF) {
                        dp[children][mask] = min(
                            dp[children][mask],
                            max(
                                dp[children - 1][
                                    mask ^ submask
                                ],
                                sum[submask]
                            )
                        );
                    }

                    if (submask == 0) {
                        break;
                    }
                }
            }
        }

        return dp[k][states - 1];
    }
};
