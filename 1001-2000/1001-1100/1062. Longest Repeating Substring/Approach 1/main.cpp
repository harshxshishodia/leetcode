class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = static_cast<int>(s.size());

        for (int length = n - 1;
             length >= 1;
             length--) {
            unordered_set<string> seen;

            for (int start = 0;
                 start + length <= n;
                 start++) {
                string current =
                    s.substr(
                        start,
                        length
                    );

                if (!seen.insert(current).second) {
                    return length;
                }
            }
        }

        return 0;
    }
};
