class Solution {
    vector<vector<int>> memo;

    bool solve(const string& s, const string& p, int i, int j) {
        if (j == p.size())
            return i == s.size();

        if (memo[i][j] != -1)
            return memo[i][j];

        bool firstMatch = i < s.size() && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.size() && p[j + 1] == '*')
            return memo[i][j] = solve(s, p, i, j + 2) || (firstMatch && solve(s, p, i + 1, j));

        return memo[i][j] = firstMatch && solve(s, p, i + 1, j + 1);
    }

public:
    bool isMatch(string s, string p) {
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, 0, 0);
    }
};