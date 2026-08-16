class Solution {
    int solve(
        const vector<int>& prices,
        int fee,
        int index,
        int canBuy,
        vector<vector<int>>& memo
    ) {
        if (index == static_cast<int>(prices.size())) {
            return 0;
        }

        if (memo[index][canBuy] != -1) {
            return memo[index][canBuy];
        }

        if (canBuy == 1) {
            memo[index][canBuy] = max(
                solve(
                    prices,
                    fee,
                    index + 1,
                    1,
                    memo
                ),
                -prices[index] +
                solve(
                    prices,
                    fee,
                    index + 1,
                    0,
                    memo
                )
            );
        } else {
            memo[index][canBuy] = max(
                solve(
                    prices,
                    fee,
                    index + 1,
                    0,
                    memo
                ),
                prices[index] -
                fee +
                solve(
                    prices,
                    fee,
                    index + 1,
                    1,
                    memo
                )
            );
        }

        return memo[index][canBuy];
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> memo(
            prices.size(),
            vector<int>(2, -1)
        );

        return solve(
            prices,
            fee,
            0,
            1,
            memo
        );
    }
};
