class Solution {
    vector<vector<vector<int>>> memo;
    vector<vector<vector<bool>>> visited;

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

        if (visited[index][amount][coupons]) {
            return memo[index][amount][coupons];
        }

        visited[index][amount][coupons] = true;

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

        memo[index][amount][coupons] =
            answer;

        return memo[index][amount][coupons];
    }

public:
    int maxTastiness(
        vector<int>& price,
        vector<int>& tastiness,
        int maxAmount,
        int maxCoupons
    ) {
        int n =
            static_cast<int>(price.size());

        memo.assign(
            n,
            vector<vector<int>>(
                maxAmount + 1,
                vector<int>(
                    maxCoupons + 1
                )
            )
        );

        visited.assign(
            n,
            vector<vector<bool>>(
                maxAmount + 1,
                vector<bool>(
                    maxCoupons + 1
                )
            )
        );

        return solve(
            price,
            tastiness,
            0,
            maxAmount,
            maxCoupons
        );
    }
};
