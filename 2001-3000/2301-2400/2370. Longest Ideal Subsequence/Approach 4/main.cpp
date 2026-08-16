class Solution {
public:
    int longestIdealString(
        string s,
        int k
    ) {
        array<int, 26> best = {};
        int answer = 0;

        for (char character : s) {
            int current =
                character - 'a';

            int previousBest = 0;

            for (int value = max(
                     0,
                     current - k
                 );
                 value <= min(
                     25,
                     current + k
                 );
                 value++) {
                previousBest = max(
                    previousBest,
                    best[value]
                );
            }

            best[current] = max(
                best[current],
                previousBest + 1
            );

            answer = max(
                answer,
                best[current]
            );
        }

        return answer;
    }
};
