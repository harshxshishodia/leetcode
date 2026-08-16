class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int seconds = 0;

        while (true) {
            bool changed =
                false;

            for (int index = 0;
                 index + 1 <
                 static_cast<int>(s.size());
                 index++) {
                if (s[index] == '0' &&
                    s[index + 1] == '1') {
                    swap(
                        s[index],
                        s[index + 1]
                    );

                    changed = true;
                    index++;
                }
            }

            if (!changed) {
                return seconds;
            }

            seconds++;
        }
    }
};
