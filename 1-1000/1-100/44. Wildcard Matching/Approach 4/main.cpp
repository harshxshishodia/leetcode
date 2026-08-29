class Solution {
public:
    bool isMatch(string s, string p) {
        int sLength = static_cast<int>(s.size());
        int pLength = static_cast<int>(p.size());
        vector<bool> previous(pLength + 1, false);
        vector<bool> current(pLength + 1, false);

        previous[0] = true;

        for (int j = 1; j <= pLength; j++) {
            if (p[j - 1] == '*') {
                previous[j] = previous[j - 1];
            }
        }

        for (int i = 1; i <= sLength; i++) {
            current[0] = false;

            for (int j = 1; j <= pLength; j++) {
                if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    current[j] = previous[j - 1];
                } else if (p[j - 1] == '*') {
                    current[j] = previous[j] || current[j - 1];
                } else {
                    current[j] = false;
                }
            }

            previous = current;
        }

        return previous[pLength];
    }
};
