class Solution {
public:
    int longestPalindromicSubsequence(
        string s,
        int k
    ) {
        int n =
            static_cast<int>(s.size());

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                n,
                vector<int>(
                    k + 1
                )
            )
        );

        for (int index = 0;
             index < n;
             index++) {
            for (int budget = 0;
                 budget <= k;
                 budget++) {
                dp[index][index][budget] =
                    1;
            }
        }

        for (int length = 2;
             length <= n;
             length++) {
            for (int left = 0;
                 left + length <= n;
                 left++) {
                int right =
                    left +
                    length -
                    1;

                int difference =
                    abs(
                        s[left] -
                        s[right]
                    );

                int cost = min(
                    difference,
                    26 -
                    difference
                );

                for (int budget = 0;
                     budget <= k;
                     budget++) {
                    dp[left][right][budget] = max(
                        dp[left + 1][right][budget],
                        dp[left][right - 1][budget]
                    );

                    if (cost <= budget) {
                        dp[left][right][budget] = max(
                            dp[left][right][budget],
                            2 +
                            (
                                length == 2
                                    ? 0
                                    : dp[left + 1][right - 1][budget - cost]
                            )
                        );
                    }
                }
            }
        }

        return dp[0][n - 1][k];
    }
};
