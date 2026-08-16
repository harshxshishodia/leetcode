class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n =
            static_cast<int>(stones.size());

        vector<int> prefix(
            n + 1
        );

        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                prefix[i] +
                stones[i];
        }

        vector<vector<int>> dp(
            n,
            vector<int>(n)
        );

        for (int length = 2;
             length <= n;
             length++) {
            for (int left = 0;
                 left + length <= n;
                 left++) {
                int right =
                    left + length - 1;

                int removeLeft =
                    prefix[right + 1] -
                    prefix[left + 1] -
                    dp[left + 1][right];

                int removeRight =
                    prefix[right] -
                    prefix[left] -
                    dp[left][right - 1];

                dp[left][right] = max(
                    removeLeft,
                    removeRight
                );
            }
        }

        return dp[0][n - 1];
    }
};
