class Solution {
public:
    bool isMatch(string s, string p) {
        int pLength = static_cast<int>(p.size());
        vector<bool> activeStates(pLength + 1, false);

        activeStates[0] = true;
        for (int j = 0; j < pLength; j++) {
            if (p[j] == '*') {
                activeStates[j + 1] = true;
            } else {
                break;
            }
        }

        for (char ch : s) {
            vector<bool> nextStates(pLength + 1, false);

            for (int j = 0; j < pLength; j++) {
                if (!activeStates[j]) {
                    continue;
                }

                if (p[j] == '?' || p[j] == ch) {
                    nextStates[j + 1] = true;
                } else if (p[j] == '*') {
                    nextStates[j] = true;
                }
            }

            for (int j = 0; j < pLength; j++) {
                if (nextStates[j] && p[j] == '*') {
                    nextStates[j + 1] = true;
                }
            }

            activeStates = move(nextStates);
        }

        return activeStates[pLength];
    }
};
