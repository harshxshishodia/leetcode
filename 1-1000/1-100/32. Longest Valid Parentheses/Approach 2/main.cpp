class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int answer = 0;
        vector<int> dp(n, 0);

        for (int index = 1; index < n; index++) {
            if (s[index] == ')' && s[index - 1] == '(') {
                dp[index] = 2;

                if (index >= 2)
                    dp[index] += dp[index - 2];
            } else if (s[index] == ')' && s[index - 1] == ')') {
                int openingIndex = index - dp[index - 1] - 1;

                if (openingIndex >= 0 && s[openingIndex] == '(') {
                    dp[index] = dp[index - 1] + 2;

                    if (openingIndex >= 1)
                        dp[index] += dp[openingIndex - 1];
                }
            }

            answer = max(answer, dp[index]);
        }

        return answer;
    }
};