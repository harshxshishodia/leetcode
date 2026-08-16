class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeroEnding = 0;
        int oneEnding = 0;

        for (char character : s) {
            int nextZero =
                zeroEnding +
                (character == '1');

            int nextOne =
                min(
                    zeroEnding,
                    oneEnding
                ) +
                (character == '0');

            zeroEnding = nextZero;
            oneEnding = nextOne;
        }

        return min(
            zeroEnding,
            oneEnding
        );
    }
};
