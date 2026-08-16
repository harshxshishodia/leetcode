class Solution {
    void backtrack(
        int n,
        int open,
        int close,
        string& current,
        vector<string>& answer
    ) {
        if (open == n && close == n) {
            answer.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            backtrack(n, open + 1, close, current, answer);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            backtrack(n, open, close + 1, current, answer);
            current.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string current;
        backtrack(n, 0, 0, current, answer);
        return answer;
    }
};
