class Solution {
    vector<array<int, 27>> memo;
    vector<array<bool, 27>> visited;

    int solve(
        const string& word,
        int index,
        int previous
    ) {
        if (index ==
            static_cast<int>(word.size())) {
            return 0;
        }

        if (visited[index][previous]) {
            return memo[index][previous];
        }

        visited[index][previous] =
            true;

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

        memo[index][previous] =
            answer;

        return answer;
    }

public:
    int removeAlmostEqualCharacters(string word) {
        memo.assign(
            word.size(),
            {}
        );

        visited.assign(
            word.size(),
            {}
        );

        return solve(
            word,
            0,
            26
        );
    }
};
