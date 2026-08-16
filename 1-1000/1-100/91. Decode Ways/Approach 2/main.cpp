class Solution {
    int solve(const string& s, int index, vector<int>& dp) {
        if (index == static_cast<int>(s.size())) {
            return 1;
        }

        if (s[index] == '0') {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int answer = solve(s, index + 1, dp);

        if (index + 1 < static_cast<int>(s.size())) {
            int value = (s[index] - '0') * 10 + (s[index + 1] - '0');

            if (value >= 10 && value <= 26) {
                answer += solve(s, index + 2, dp);
            }
        }

        dp[index] = answer;
        return dp[index];
    }

public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
};
