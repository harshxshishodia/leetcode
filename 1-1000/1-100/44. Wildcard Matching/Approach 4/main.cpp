class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<bool> next(n + 1, false);
        vector<bool> current(n + 1, false);

        for (int i = m; i >= 0; i--) {
            fill(current.begin(), current.end(), false);
            current[n] = i == m;

            for (int j = n - 1; j >= 0; j--) {
                if (p[j] == '*')
                    current[j] = current[j + 1] || (i < m && next[j]);
                else
                    current[j] = i < m && (s[i] == p[j] || p[j] == '?') && next[j + 1];
            }

            next = current;
        }

        return next[0];
    }
};