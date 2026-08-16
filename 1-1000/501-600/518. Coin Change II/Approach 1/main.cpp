class Solution {
    int solve(
        const vector<int>& coins,
        int index,
        int amount
    ) {
        if (amount == 0) {
            return 1;
        }

        if (index == static_cast<int>(coins.size()) || amount < 0) {
            return 0;
        }

        int skip = solve(
            coins,
            index + 1,
            amount
        );

        int take = solve(
            coins,
            index,
            amount - coins[index]
        );

        return skip + take;
    }

public:
    int change(int amount, vector<int>& coins) {
        return solve(coins, 0, amount);
    }
};
