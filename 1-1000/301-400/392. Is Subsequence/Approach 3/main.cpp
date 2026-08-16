class Solution {
    int lcs(const string& s, const string& t, int first, int second, vector<vector<int>>& dp) {
        if (first == static_cast<int>(s.size()) || second == static_cast<int>(t.size())) {
            return 0;
        }

        if (dp[first][second] != -1) {
            return dp[first][second];
        }

        if (s[first] == t[second]) {
            dp[first][second] = 1 + lcs(s, t, first + 1, second + 1, dp);
        } else {
            dp[first][second] = max(
                lcs(s, t, first + 1, second, dp),
                lcs(s, t, first, second + 1, dp)
            );
        }

        return dp[first][second];
    }

public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return lcs(s, t, 0, 0, dp) == static_cast<int>(s.size());
    }
};
