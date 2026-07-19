class Solution {
public:
    bool isMatch(string s, string p) {
        int stringIndex = 0;
        int patternIndex = 0;
        int starIndex = -1;
        int matchedIndex = 0;

        while (stringIndex < s.size()) {
            if (patternIndex < p.size() && (s[stringIndex] == p[patternIndex] || p[patternIndex] == '?')) {
                stringIndex++;
                patternIndex++;
            } else if (patternIndex < p.size() && p[patternIndex] == '*') {
                starIndex = patternIndex;
                matchedIndex = stringIndex;
                patternIndex++;
            } else if (starIndex != -1) {
                patternIndex = starIndex + 1;
                matchedIndex++;
                stringIndex = matchedIndex;
            } else {
                return false;
            }
        }

        while (patternIndex < p.size() && p[patternIndex] == '*')
            patternIndex++;

        return patternIndex == p.size();
    }
};