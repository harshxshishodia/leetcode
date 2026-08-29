class Solution {
public:
    bool isMatch(string s, string p) {
        int sIndex = 0;
        int pIndex = 0;
        int starIndex = -1;
        int matchIndex = 0;
        int sLength = static_cast<int>(s.size());
        int pLength = static_cast<int>(p.size());

        while (sIndex < sLength) {
            if (pIndex < pLength && (p[pIndex] == '?' || p[pIndex] == s[sIndex])) {
                sIndex++;
                pIndex++;
            } else if (pIndex < pLength && p[pIndex] == '*') {
                starIndex = pIndex;
                matchIndex = sIndex;
                pIndex++;
            } else if (starIndex != -1) {
                pIndex = starIndex + 1;
                matchIndex++;
                sIndex = matchIndex;
            } else {
                return false;
            }
        }

        while (pIndex < pLength && p[pIndex] == '*') {
            pIndex++;
        }

        return pIndex == pLength;
    }
};
