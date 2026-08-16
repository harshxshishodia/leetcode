class Solution {
public:
    bool isSubsequence(string s, string t) {
        int firstLength = static_cast<int>(s.size());
        int secondLength = static_cast<int>(t.size());
        vector<int> next(secondLength + 1);
        vector<int> current(secondLength + 1);

        for (int first = firstLength - 1; first >= 0; first--) {
            for (int second = secondLength - 1; second >= 0; second--) {
                if (s[first] == t[second]) {
                    current[second] = 1 + next[second + 1];
                } else {
                    current[second] = max(next[second], current[second + 1]);
                }
            }

            next = current;
        }

        return next[0] == firstLength;
    }
};
