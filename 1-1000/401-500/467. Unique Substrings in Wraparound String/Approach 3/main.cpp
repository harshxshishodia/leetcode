class Solution {
public:
    int findSubstringInWraproundString(string s) {
        array<int, 26> longest = {};
        int currentLength = 0;

        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            if (i > 0 &&
                (s[i - 1] - 'a' + 1) % 26 == s[i] - 'a') {
                currentLength++;
            } else {
                currentLength = 1;
            }

            int index = s[i] - 'a';
            longest[index] = max(
                longest[index],
                currentLength
            );
        }

        return accumulate(
            longest.begin(),
            longest.end(),
            0
        );
    }
};
