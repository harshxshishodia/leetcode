class Solution {
public:
    int longestValidParentheses(string s) {
        int answer = 0;
        stack<int> indices;
        indices.push(-1);

        for (int index = 0; index < s.size(); index++) {
            if (s[index] == '(') {
                indices.push(index);
            } else {
                indices.pop();

                if (indices.empty())
                    indices.push(index);
                else
                    answer = max(answer, index - indices.top());
            }
        }

        return answer;
    }
};