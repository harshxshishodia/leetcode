class Solution {
    int solve(
        const vector<int>& piles,
        int left,
        int right
    ) {
        if (left == right) {
            return piles[left];
        }

        return max(
            piles[left] -
            solve(
                piles,
                left + 1,
                right
            ),
            piles[right] -
            solve(
                piles,
                left,
                right - 1
            )
        );
    }

public:
    bool stoneGame(vector<int>& piles) {
        return solve(
            piles,
            0,
            static_cast<int>(piles.size()) - 1
        ) > 0;
    }
};
