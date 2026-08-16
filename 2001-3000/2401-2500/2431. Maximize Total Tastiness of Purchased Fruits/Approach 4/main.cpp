class Solution {
public:
    int maxTastiness(
        vector<int>& price,
        vector<int>& tastiness,
        int maxAmount,
        int maxCoupons
    ) {
        vector<vector<int>> dp(
            maxAmount + 1,
            vector<int>(
                maxCoupons + 1
            )
        );

        for (int index = 0;
             index < static_cast<int>(price.size());
             index++) {
            int fullPrice =
                price[index];

            int couponPrice =
                fullPrice /
                2;

            int taste =
                tastiness[index];

            vector<vector<int>> previous =
                dp;

            for (int amount = 0;
                 amount <= maxAmount;
                 amount++) {
                for (int coupons = 0;
                     coupons <= maxCoupons;
                     coupons++) {
                    if (fullPrice <= amount) {
                        dp[amount][coupons] = max(
                            dp[amount][coupons],
                            taste +
                            previous[
                                amount -
                                fullPrice
                            ][coupons]
                        );
                    }

                    if (coupons > 0 &&
                        couponPrice <= amount) {
                        dp[amount][coupons] = max(
                            dp[amount][coupons],
                            taste +
                            previous[
                                amount -
                                couponPrice
                            ][coupons - 1]
                        );
                    }
                }
            }
        }

        return dp[maxAmount][maxCoupons];
    }
};
