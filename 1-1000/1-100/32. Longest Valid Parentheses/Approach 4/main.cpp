class Solution {
public:
    int longestValidParentheses(string s) {
        int answer = 0;
        int open = 0;
        int close = 0;

        for (int index = 0; index < s.size(); index++) {
            if (s[index] == '(')
                open++;
            else
                close++;

            if (open == close)
                answer = max(answer, open + close);
            else if (close > open) {
                open = 0;
                close = 0;
            }
        }

        open = 0;
        close = 0;

        for (int index = s.size() - 1; index >= 0; index--) {
            if (s[index] == '(')
                open++;
            else
                close++;

            if (open == close)
                answer = max(answer, open + close);
            else if (open > close) {
                open = 0;
                close = 0;
            }
        }

        return answer;
    }
};