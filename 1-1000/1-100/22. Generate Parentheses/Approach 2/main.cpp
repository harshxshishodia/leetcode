class Solution {
    void solve(int n, int open, int close, string& current, vector<string>& result) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            solve(n, open + 1, close, current, result);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            solve(n, open, close + 1, current, result);
            current.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        solve(n, 0, 0, current, result);
        return result;
    }
};