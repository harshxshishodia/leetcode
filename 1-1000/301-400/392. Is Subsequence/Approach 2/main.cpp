class Solution {
    int lcs(const string& s, const string& t, int first, int second) {
        if (first == static_cast<int>(s.size()) || second == static_cast<int>(t.size())) {
            return 0;
        }

        if (s[first] == t[second]) {
            return 1 + lcs(s, t, first + 1, second + 1);
        }

        return max(lcs(s, t, first + 1, second), lcs(s, t, first, second + 1));
    }

public:
    bool isSubsequence(string s, string t) {
        return lcs(s, t, 0, 0) == static_cast<int>(s.size());
    }
};
