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
                bool firstMatch = i < m && (s[i] == p[j] || p[j] == '.');

                if (j + 1 < n && p[j + 1] == '*')
                    current[j] = current[j + 2] || (firstMatch && next[j]);
                else
                    current[j] = firstMatch && next[j + 1];
            }

            next = current;
        }

        return next[0];
    }
};