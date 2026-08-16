class Solution {
    int solve(
        const vector<int>& coins,
        int index,
        int amount,
        vector<vector<int>>& memo
    ) {
        if (amount == 0) {
            return 0;
        }

        if (index == static_cast<int>(coins.size()) ||
            amount < 0) {
            return 1000000000;
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

        int take = 1000000000;

        if (coins[index] <= amount) {
            take = 1 + solve(
                coins,
                index,
                amount - coins[index],
                memo
            );
        }

        memo[index][amount] = min(skip, take);
        return memo[index][amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(
            coins.size(),
            vector<int>(amount + 1, -1)
        );

        int answer = solve(
            coins,
            0,
            amount,
            memo
        );

        return answer >= 1000000000 ? -1 : answer;
    }
};
