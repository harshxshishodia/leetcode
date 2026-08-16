class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(
            m + 1,
            vector<int>(n + 1)
        );

        for (const string& s : strs) {
            int zeroes = 0;
            int ones = 0;

            for (char character : s) {
                if (character == '0') {
                    zeroes++;
                } else {
                    ones++;
                }
            }

            for (int z = m; z >= zeroes; z--) {
                for (int o = n; o >= ones; o--) {
                    dp[z][o] = max(
                        dp[z][o],
                        1 + dp[z - zeroes][o - ones]
                    );
                }
            }
        }

        return dp[m][n];
    }
};
