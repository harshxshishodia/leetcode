class Solution {
    int solve(
        const vector<int>& prices,
        int fee,
        int index,
        bool canBuy
    ) {
        if (index == static_cast<int>(prices.size())) {
            return 0;
        }

        if (canBuy) {
            return max(
                solve(
                    prices,
                    fee,
                    index + 1,
                    true
                ),
                -prices[index] +
                solve(
                    prices,
                    fee,
                    index + 1,
                    false
                )
            );
        }

        return max(
            solve(
                prices,
                fee,
                index + 1,
                false
            ),
            prices[index] -
            fee +
            solve(
                prices,
                fee,
                index + 1,
                true
            )
        );
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        return solve(
            prices,
            fee,
            0,
            true
        );
    }
};
