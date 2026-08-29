class Solution {
public:
    bool isMatch(string s, string p) {
        int sLength = static_cast<int>(s.size());
        int pLength = static_cast<int>(p.size());
        vector<bool> dp(pLength + 1, false);

        dp[0] = true;

        for (int j = 1; j <= pLength; j++) {
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 1];
            }
        }

        for (int i = 1; i <= sLength; i++) {
            bool diagonal = dp[0];
            dp[0] = false;

            for (int j = 1; j <= pLength; j++) {
                bool fromTop = dp[j];

                if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    dp[j] = diagonal;
                } else if (p[j - 1] == '*') {
                    dp[j] = fromTop || dp[j - 1];
                } else {
                    dp[j] = false;
                }

                diagonal = fromTop;
            }
        }

        return dp[pLength];
    }
};
