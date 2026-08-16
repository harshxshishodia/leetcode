class Solution {
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

        vector<vector<int>> dp(
            n + 1,
            vector<int>(
                n + 1
            )
        );

        for (int index = n - 1;
             index >= 0;
             index--) {
            for (int m = n;
                 m >= 1;
                 m--) {
                if (index + 2 * m >= n) {
                    dp[index][m] =
                        suffix[index];

                    continue;
                }

                int opponentBest =
                    numeric_limits<int>::max();

                for (int x = 1;
                     x <= 2 * m;
                     x++) {
                    opponentBest = min(
                        opponentBest,
                        dp[index + x][max(m, x)]
                    );
                }

                dp[index][m] =
                    suffix[index] -
                    opponentBest;
            }
        }

        return dp[0][1];
    }
};
