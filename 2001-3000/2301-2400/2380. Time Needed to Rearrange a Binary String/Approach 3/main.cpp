class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int zeroes = 0;
        int seconds = 0;

        for (char character : s) {
            if (character == '0') {
                zeroes++;
            } else if (zeroes > 0) {
                seconds = max(
                    seconds + 1,
                    zeroes
                );
            }
        }

        return seconds;
    }
};
