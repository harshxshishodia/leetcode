class Solution {
    int solve(
        const vector<int>& coins,
        int index,
        int amount,
        vector<vector<int>>& memo
    ) {
        if (amount == 0) {
            return 1;
        }

        if (index == static_cast<int>(coins.size()) || amount < 0) {
            return 0;
        }

        if (memo[index][amount] != -1) {
            return memo[index][amount];
        }

        int skip = solve(
            coins,
            index + 1,
            amount,
            memo
        );

        int take = 0;

        if (coins[index] <= amount) {
            take = solve(
                coins,
                index,
                amount - coins[index],
                memo
            );
        }

        memo[index][amount] = skip + take;
        return memo[index][amount];
    }

public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(
            coins.size(),
            vector<int>(amount + 1, -1)
        );

        return solve(
            coins,
            0,
            amount,
            memo
        );
    }
};
