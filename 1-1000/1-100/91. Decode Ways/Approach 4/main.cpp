class Solution {
public:
    int numDecodings(string s) {
        int n = static_cast<int>(s.size());
        int next1 = 1;
        int next2 = 0;

        for (int index = n - 1; index >= 0; index--) {
            int current = 0;

            if (s[index] != '0') {
                current = next1;

                if (index + 1 < n) {
                    int value = (s[index] - '0') * 10 + (s[index + 1] - '0');

                    if (value >= 10 && value <= 26) {
                        current += index + 2 == n ? 1 : next2;
                    }
                }
            }

            next2 = next1;
            next1 = current;
        }

        return next1;
    }
};
