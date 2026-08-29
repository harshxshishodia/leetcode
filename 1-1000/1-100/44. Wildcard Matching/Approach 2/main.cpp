class Solution {
    bool solve(
        const string& s,
        const string& p,
        int i,
        int j,
        vector<vector<int>>& memo
    ) {
        if (i == static_cast<int>(s.size()) && j == static_cast<int>(p.size())) {
            return true;
        }

        if (j == static_cast<int>(p.size())) {
            return false;
        }

        if (i == static_cast<int>(s.size())) {
            for (int k = j; k < static_cast<int>(p.size()); k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (p[j] == '?' || p[j] == s[i]) {
            return memo[i][j] = solve(s, p, i + 1, j + 1, memo);
        }

        if (p[j] == '*') {
            return memo[i][j] = (solve(s, p, i, j + 1, memo) || solve(s, p, i + 1, j, memo));
        }

        return memo[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        int sLength = static_cast<int>(s.size());
        int pLength = static_cast<int>(p.size());
        vector<vector<int>> memo(
            sLength + 1,
            vector<int>(pLength + 1, -1)
        );

        return solve(s, p, 0, 0, memo);
    }
};
