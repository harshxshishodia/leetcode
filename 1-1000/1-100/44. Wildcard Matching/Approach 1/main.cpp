class Solution {
    bool solve(const string& s, const string& p, int i, int j) {
        if (j == p.size())
            return i == s.size();

        if (p[j] == '*')
            return solve(s, p, i, j + 1) || (i < s.size() && solve(s, p, i + 1, j));

        if (i < s.size() && (s[i] == p[j] || p[j] == '?'))
            return solve(s, p, i + 1, j + 1);

        return false;
    }

public:
    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};