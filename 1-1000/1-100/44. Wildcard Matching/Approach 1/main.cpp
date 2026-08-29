class Solution {
    bool solve(const string& s, const string& p, int i, int j) {
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

        if (p[j] == '?' || p[j] == s[i]) {
            return solve(s, p, i + 1, j + 1);
        }

        if (p[j] == '*') {
            return solve(s, p, i, j + 1) || solve(s, p, i + 1, j);
        }

        return false;
    }

public:
    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};
