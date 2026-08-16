class Solution {
    int solve(
        const vector<int>& piles,
        int left,
        int right,
        vector<vector<int>>& memo
    ) {
        if (left == right) {
            return piles[left];
        }

        if (memo[left][right] != numeric_limits<int>::min()) {
            return memo[left][right];
        }

        memo[left][right] = max(
            piles[left] -
            solve(
                piles,
                left + 1,
                right,
                memo
            ),
            piles[right] -
            solve(
                piles,
                left,
                right - 1,
                memo
            )
        );

        return memo[left][right];
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = static_cast<int>(piles.size());

        vector<vector<int>> memo(
            n,
            vector<int>(
                n,
                numeric_limits<int>::min()
            )
        );

        return solve(
            piles,
            0,
            n - 1,
            memo
        ) > 0;
    }
};
