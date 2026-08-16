class Solution {
    vector<vector<vector<int>>> memo;
    vector<string> words;

    int solve(
        int index,
        int first,
        int last
    ) {
        if (index ==
            static_cast<int>(words.size())) {
            return 0;
        }

        int& answer =
            memo[index][first][last];

        if (answer != -1) {
            return answer;
        }

        int wordFirst =
            words[index].front() -
            'a';

        int wordLast =
            words[index].back() -
            'a';

        int length =
            static_cast<int>(
                words[index].size()
            );

        int append =
            length -
            (
                last ==
                wordFirst
            ) +
            solve(
                index + 1,
                first,
                wordLast
            );

        int prepend =
            length -
            (
                wordLast ==
                first
            ) +
            solve(
                index + 1,
                wordFirst,
                last
            );

        answer = min(
            append,
            prepend
        );

        return answer;
    }

public:
    int minimizeConcatenatedLength(
        vector<string>& input
    ) {
        words =
            input;

        int n =
            static_cast<int>(words.size());

        memo.assign(
            n,
            vector<vector<int>>(
                26,
                vector<int>(
                    26,
                    -1
                )
            )
        );

        return
            static_cast<int>(
                words[0].size()
            ) +
            solve(
                1,
                words[0].front() -
                'a',
                words[0].back() -
                'a'
            );
    }
};
