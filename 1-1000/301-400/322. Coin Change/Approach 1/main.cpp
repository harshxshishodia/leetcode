class Solution {
    int solve(
        const vector<int>& coins,
        int index,
        int amount
    ) {
        if (amount == 0) {
            return 0;
        }

        if (index == static_cast<int>(coins.size()) ||
            amount < 0) {
            return 1000000000;
        }

        int skip = solve(
            coins,
            index + 1,
            amount
        );

        int take = 1000000000;

        if (coins[index] <= amount) {
            take = 1 + solve(
                coins,
                index,
                amount - coins[index]
            );
        }

        return min(skip, take);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int answer = solve(coins, 0, amount);
        return answer >= 1000000000 ? -1 : answer;
    }
};
