class Solution {
public:
    bool isSubsequence(string s, string t) {
        int firstLength = static_cast<int>(s.size());
        int secondLength = static_cast<int>(t.size());
        vector<vector<int>> dp(firstLength + 1, vector<int>(secondLength + 1));

        for (int first = firstLength - 1; first >= 0; first--) {
            for (int second = secondLength - 1; second >= 0; second--) {
                if (s[first] == t[second]) {
                    dp[first][second] = 1 + dp[first + 1][second + 1];
                } else {
                    dp[first][second] = max(dp[first + 1][second], dp[first][second + 1]);
                }
            }
        }

        return dp[0][0] == firstLength;
    }
};
