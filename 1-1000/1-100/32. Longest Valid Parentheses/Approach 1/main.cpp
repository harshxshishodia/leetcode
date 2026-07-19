class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int answer = 0;

        for (int start = 0; start < n; start++) {
            int balance = 0;

            for (int end = start; end < n; end++) {
                if (s[end] == '(')
                    balance++;
                else
                    balance--;

                if (balance < 0)
                    break;

                if (balance == 0)
                    answer = max(answer, end - start + 1);
            }
        }

        return answer;
    }
};