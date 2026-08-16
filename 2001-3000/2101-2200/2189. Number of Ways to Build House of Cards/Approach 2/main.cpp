class Solution {
    vector<vector<int>> memo;

    int solve(
        const vector<int>& rows,
        int index,
        int remaining
    ) {
        if (remaining == 0) {
            return 1;
        }

        if (index == static_cast<int>(rows.size()) ||
            remaining < 0) {
            return 0;
        }

        if (memo[index][remaining] != -1) {
            return memo[index][remaining];
        }

        memo[index][remaining] =
            solve(
                rows,
                index + 1,
                remaining
            ) +
            solve(
                rows,
                index + 1,
                remaining - rows[index]
            );

        return memo[index][remaining];
    }

public:
    int houseOfCards(int n) {
        vector<int> rows;

        for (int cards = 2;
             cards <= n;
             cards += 3) {
            rows.push_back(cards);
        }

        memo.assign(
            rows.size(),
            vector<int>(
                n + 1,
                -1
            )
        );

        return solve(
            rows,
            0,
            n
        );
    }
};
