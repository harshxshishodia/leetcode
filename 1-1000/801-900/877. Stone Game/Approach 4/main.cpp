class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = static_cast<int>(piles.size());
        vector<int> dp = piles;

        for (int length = 2; length <= n; length++) {
            for (int left = 0;
                 left + length <= n;
                 left++) {
                int right =
                    left + length - 1;

                dp[left] = max(
                    piles[left] -
                    dp[left + 1],
                    piles[right] -
                    dp[left]
                );
            }
        }

        return dp[0] > 0;
    }
};
