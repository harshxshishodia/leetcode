class Solution {
    vector<vector<int>> memo;

    bool solve(const string& s, const string& p, int i, int j) {
        if (j == p.size())
            return i == s.size();

        if (memo[i][j] != -1)
            return memo[i][j];

        if (p[j] == '*')
            return memo[i][j] = solve(s, p, i, j + 1) || (i < s.size() && solve(s, p, i + 1, j));

        if (i < s.size() && (s[i] == p[j] || p[j] == '?'))
            return memo[i][j] = solve(s, p, i + 1, j + 1);

        return memo[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, 0, 0);
    }
};