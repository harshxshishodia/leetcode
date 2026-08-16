class Solution {
    int solve(
        const vector<int>& piles,
        const vector<int>& suffix,
        int index,
        int m
    ) {
        if (index >= static_cast<int>(piles.size())) {
            return 0;
        }

        if (index + 2 * m >=
            static_cast<int>(piles.size())) {
            return suffix[index];
        }

        int opponentBest =
            numeric_limits<int>::max();

        for (int x = 1; x <= 2 * m; x++) {
            opponentBest = min(
                opponentBest,
                solve(
                    piles,
                    suffix,
                    index + x,
                    max(
                        m,
                        x
                    )
                )
            );
        }

        return
            suffix[index] -
            opponentBest;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n =
            static_cast<int>(piles.size());

        vector<int> suffix(
            n + 1
        );

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] =
                suffix[i + 1] +
                piles[i];
        }

        return solve(
            piles,
            suffix,
            0,
            1
        );
    }
};
