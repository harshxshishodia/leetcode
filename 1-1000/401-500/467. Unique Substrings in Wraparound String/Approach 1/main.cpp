class Solution {
    bool valid(const string& s) {
        for (int i = 1; i < static_cast<int>(s.size()); i++) {
            int previous = s[i - 1] - 'a';
            int current = s[i] - 'a';

            if ((previous + 1) % 26 != current) {
                return false;
            }
        }

        return true;
    }

public:
    int findSubstringInWraproundString(string s) {
        unordered_set<string> unique;

        for (int left = 0; left < static_cast<int>(s.size()); left++) {
            for (int right = left;
                 right < static_cast<int>(s.size());
                 right++) {
                string current = s.substr(
                    left,
                    right - left + 1
                );

                if (valid(current)) {
                    unique.insert(current);
                }
            }
        }

        return static_cast<int>(unique.size());
    }
};
