class Solution {
public:
    int numDecodings(string s) {
        int n = static_cast<int>(s.size());
        vector<int> dp(n + 1);
        dp[n] = 1;

        for (int index = n - 1; index >= 0; index--) {
            if (s[index] == '0') {
                dp[index] = 0;
                continue;
            }

            dp[index] = dp[index + 1];

            if (index + 1 < n) {
                int value = (s[index] - '0') * 10 + (s[index + 1] - '0');

                if (value >= 10 && value <= 26) {
                    dp[index] += dp[index + 2];
                }
            }
        }

        return dp[0];
    }
};
