class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftParentheses;
        stack<int> stars;

        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            if (s[i] == '(') {
                leftParentheses.push(i);
            } else if (s[i] == '*') {
                stars.push(i);
            } else {
                if (!leftParentheses.empty()) {
                    leftParentheses.pop();
                } else if (!stars.empty()) {
                    stars.pop();
                } else {
                    return false;
                }
            }
        }

        while (!leftParentheses.empty() &&
               !stars.empty()) {
            if (leftParentheses.top() > stars.top()) {
                return false;
            }

            leftParentheses.pop();
            stars.pop();
        }

        return leftParentheses.empty();
    }
};
