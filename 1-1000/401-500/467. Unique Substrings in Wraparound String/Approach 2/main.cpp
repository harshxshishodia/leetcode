class Solution {
public:
    int findSubstringInWraproundString(string s) {
        unordered_set<string> unique;

        for (int left = 0; left < static_cast<int>(s.size()); left++) {
            string current;
            current.push_back(s[left]);
            unique.insert(current);

            for (int right = left + 1;
                 right < static_cast<int>(s.size());
                 right++) {
                int previous = s[right - 1] - 'a';
                int next = s[right] - 'a';

                if ((previous + 1) % 26 != next) {
                    break;
                }

                current.push_back(s[right]);
                unique.insert(current);
            }
        }

        return static_cast<int>(unique.size());
    }
};
