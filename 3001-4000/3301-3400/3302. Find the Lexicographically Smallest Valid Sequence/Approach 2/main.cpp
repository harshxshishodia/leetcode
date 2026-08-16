class Solution {
    vector<vector<array<int, 2>>> memo;
    string word1;
    string word2;

    int possible(
        int first,
        int second,
        int used
    ) {
        if (second ==
            static_cast<int>(word2.size())) {
            return 1;
        }

        if (
            static_cast<int>(word1.size()) -
            first <
            static_cast<int>(word2.size()) -
            second
        ) {
            return 0;
        }

        if (memo[first][second][used] != -1) {
            return memo[first][second][used];
        }

        int answer =
            possible(
                first + 1,
                second,
                used
            );

        if (
            word1[first] ==
            word2[second]
        ) {
            answer = max(
                answer,
                possible(
                    first + 1,
                    second + 1,
                    used
                )
            );
        } else if (!used) {
            answer = max(
                answer,
                possible(
                    first + 1,
                    second + 1,
                    1
                )
            );
        }

        memo[first][second][used] =
            answer;

        return answer;
    }

public:
    vector<int> validSequence(
        string inputWord1,
        string inputWord2
    ) {
        word1 =
            inputWord1;

        word2 =
            inputWord2;

        int n =
            static_cast<int>(word1.size());

        int m =
            static_cast<int>(word2.size());

        memo.assign(
            n,
            vector<array<int, 2>>(
                m,
                array<int, 2>{
                    -1,
                    -1
                }
            )
        );

        if (!possible(
                0,
                0,
                0)) {
            return {};
        }

        vector<int> answer;

        int first = 0;
        int second = 0;
        int used = 0;

        while (second < m) {
            for (int index = first;
                 index < n;
                 index++) {
                int nextUsed =
                    used +
                    (
                        word1[index] !=
                        word2[second]
                    );

                if (nextUsed > 1) {
                    continue;
                }

                if (
                    second + 1 == m ||
                    possible(
                        index + 1,
                        second + 1,
                        nextUsed
                    )
                ) {
                    answer.push_back(
                        index
                    );

                    first =
                        index + 1;

                    second++;

                    used =
                        nextUsed;

                    break;
                }
            }
        }

        return answer;
    }
};
