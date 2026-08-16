class Solution {
    vector<int> memo;

    int solve(
        const string& word,
        int index
    ) {
        if (index ==
            static_cast<int>(word.size())) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int answer =
            numeric_limits<int>::max();

        int end =
            index;

        while (end <
               static_cast<int>(word.size()) &&
               end - index < 3) {
            if (end > index &&
                word[end] <=
                word[end - 1]) {
                break;
            }

            int length =
                end -
                index +
                1;

            answer = min(
                answer,
                3 -
                length +
                solve(
                    word,
                    end + 1
                )
            );

            end++;
        }

        memo[index] =
            answer;

        return memo[index];
    }

public:
    int addMinimum(string word) {
        memo.assign(
            word.size(),
            -1
        );

        return solve(
            word,
            0
        );
    }
};
