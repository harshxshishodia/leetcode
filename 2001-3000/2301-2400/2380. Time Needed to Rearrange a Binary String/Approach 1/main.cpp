class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int seconds = 0;

        while (true) {
            string next =
                s;

            bool changed =
                false;

            for (int index = 0;
                 index + 1 <
                 static_cast<int>(s.size());
                 index++) {
                if (s[index] == '0' &&
                    s[index + 1] == '1') {
                    next[index] = '1';
                    next[index + 1] = '0';

                    changed = true;
                    index++;
                }
            }

            if (!changed) {
                return seconds;
            }

            s = next;
            seconds++;
        }
    }
};
