class Solution {
public:
    string longestPalindrome(string s) {
        int n = static_cast<int>(s.size());
        vector<vector<bool>> dp(n, vector<bool>(n));
        int bestStart = 0;
        int bestLength = 1;

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int length = 2; length <= n; length++) {
            for (int start = 0; start + length <= n; start++) {
                int end = start + length - 1;

                if (s[start] == s[end] &&
                    (length == 2 || dp[start + 1][end - 1])) {
                    dp[start][end] = true;

                    if (length > bestLength) {
                        bestStart = start;
                        bestLength = length;
                    }
                }
            }
        }

        return s.substr(bestStart, bestLength);
    }
};
