class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int count = static_cast<int>(strs.size());

        vector<vector<vector<int>>> dp(
            count + 1,
            vector<vector<int>>(
                m + 1,
                vector<int>(n + 1)
            )
        );

        for (int index = 1; index <= count; index++) {
            int zeroes = 0;
            int ones = 0;

            for (char character : strs[index - 1]) {
                if (character == '0') {
                    zeroes++;
                } else {
                    ones++;
                }
            }

            for (int z = 0; z <= m; z++) {
                for (int o = 0; o <= n; o++) {
                    dp[index][z][o] =
                        dp[index - 1][z][o];

                    if (zeroes <= z && ones <= o) {
                        dp[index][z][o] = max(
                            dp[index][z][o],
                            1 + dp[index - 1][z - zeroes][o - ones]
                        );
                    }
                }
            }
        }

        return dp[count][m][n];
    }
};
