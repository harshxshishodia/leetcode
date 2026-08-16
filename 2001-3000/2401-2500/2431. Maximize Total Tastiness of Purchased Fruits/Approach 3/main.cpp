class Solution {
public:
    int maxTastiness(
        vector<int>& price,
        vector<int>& tastiness,
        int maxAmount,
        int maxCoupons
    ) {
        int n =
            static_cast<int>(price.size());

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(
                maxAmount + 1,
                vector<int>(
                    maxCoupons + 1
                )
            )
        );

        for (int index = 1;
             index <= n;
             index++) {
            int fullPrice =
                price[index - 1];

            int couponPrice =
                fullPrice /
                2;

            int taste =
                tastiness[index - 1];

            for (int amount = 0;
                 amount <= maxAmount;
                 amount++) {
                for (int coupons = 0;
                     coupons <= maxCoupons;
                     coupons++) {
                    dp[index][amount][coupons] =
                        dp[index - 1][amount][coupons];

                    if (fullPrice <= amount) {
                        dp[index][amount][coupons] = max(
                            dp[index][amount][coupons],
                            taste +
                            dp[index - 1][
                                amount -
                                fullPrice
                            ][coupons]
                        );
                    }

                    if (coupons > 0 &&
                        couponPrice <= amount) {
                        dp[index][amount][coupons] = max(
                            dp[index][amount][coupons],
                            taste +
                            dp[index - 1][
                                amount -
                                couponPrice
                            ][coupons - 1]
                        );
                    }
                }
            }
        }

        return dp[n][maxAmount][maxCoupons];
    }
};
