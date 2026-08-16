class Solution {
public:
    bool isSubsequence(string s, string t) {
        int first = 0;

        for (int second = 0; second < static_cast<int>(t.size()) && first < static_cast<int>(s.size()); second++) {
            if (s[first] == t[second]) {
                first++;
            }
        }

        return first == static_cast<int>(s.size());
    }
};
