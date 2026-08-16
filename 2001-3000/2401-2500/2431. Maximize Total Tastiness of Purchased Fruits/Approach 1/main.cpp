class Solution {
    int solve(
        const vector<int>& price,
        const vector<int>& tastiness,
        int index,
        int amount,
        int coupons
    ) {
        if (index ==
            static_cast<int>(price.size())) {
            return 0;
        }

        int answer =
            solve(
                price,
                tastiness,
                index + 1,
                amount,
                coupons
            );

        if (price[index] <= amount) {
            answer = max(
                answer,
                tastiness[index] +
                solve(
                    price,
                    tastiness,
                    index + 1,
                    amount -
                    price[index],
                    coupons
                )
            );
        }

        int couponPrice =
            price[index] /
            2;

        if (coupons > 0 &&
            couponPrice <= amount) {
            answer = max(
                answer,
                tastiness[index] +
                solve(
                    price,
                    tastiness,
                    index + 1,
                    amount -
                    couponPrice,
                    coupons - 1
                )
            );
        }

        return answer;
    }

public:
    int maxTastiness(
        vector<int>& price,
        vector<int>& tastiness,
        int maxAmount,
        int maxCoupons
    ) {
        return solve(
            price,
            tastiness,
            0,
            maxAmount,
            maxCoupons
        );
    }
};
