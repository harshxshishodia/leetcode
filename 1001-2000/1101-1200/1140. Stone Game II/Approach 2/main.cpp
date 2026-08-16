class Solution {
    vector<vector<int>> memo;
    vector<int> suffix;
    int n;

    int solve(
        int index,
        int m
    ) {
        if (index >= n) {
            return 0;
        }

        if (index + 2 * m >= n) {
            return suffix[index];
        }

        if (memo[index][m] != -1) {
            return memo[index][m];
        }

        int opponentBest =
            numeric_limits<int>::max();

        for (int x = 1; x <= 2 * m; x++) {
            opponentBest = min(
                opponentBest,
                solve(
                    index + x,
                    max(
                        m,
                        x
                    )
                )
            );
        }

        memo[index][m] =
            suffix[index] -
            opponentBest;

        return memo[index][m];
    }

public:
    int stoneGameII(vector<int>& piles) {
        n =
            static_cast<int>(piles.size());

        suffix.assign(
            n + 1,
            0
        );

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] =
                suffix[i + 1] +
                piles[i];
        }

        memo.assign(
            n,
            vector<int>(
                n + 1,
                -1
            )
        );

        return solve(
            0,
            1
        );
    }
};
