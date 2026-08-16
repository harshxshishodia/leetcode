class Solution {
    int solve(
        const string& word,
        int index,
        int previous
    ) {
        if (index ==
            static_cast<int>(word.size())) {
            return 0;
        }

        int answer =
            numeric_limits<int>::max();

        for (int current = 0;
             current < 26;
             current++) {
            if (
                previous != 26 &&
                abs(
                    current -
                    previous
                ) <= 1
            ) {
                continue;
            }

            int cost =
                word[index] -
                'a' !=
                current;

            answer = min(
                answer,
                cost +
                solve(
                    word,
                    index + 1,
                    current
                )
            );
        }

        return answer;
    }

public:
    int removeAlmostEqualCharacters(string word) {
        return solve(
            word,
            0,
            26
        );
    }
};
