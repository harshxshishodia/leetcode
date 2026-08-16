class Solution {
public:
    bool checkValidString(string s) {
        int n = static_cast<int>(s.size());

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(n + 1)
        );

        dp[0][0] = true;

        for (int index = 0; index < n; index++) {
            for (int balance = 0; balance <= n; balance++) {
                if (!dp[index][balance]) {
                    continue;
                }

                if (s[index] == '(') {
                    dp[index + 1][balance + 1] = true;
                } else if (s[index] == ')') {
                    if (balance > 0) {
                        dp[index + 1][balance - 1] = true;
                    }
                } else {
                    dp[index + 1][balance] = true;
                    dp[index + 1][balance + 1] = true;

                    if (balance > 0) {
                        dp[index + 1][balance - 1] = true;
                    }
                }
            }
        }

        return dp[n][0];
    }
};
