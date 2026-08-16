class Solution {
public:
    vector<int> validSequence(
        string word1,
        string word2
    ) {
        int n =
            static_cast<int>(word1.size());

        int m =
            static_cast<int>(word2.size());

        vector<int> suffix(
            m + 1,
            n
        );

        int first =
            n -
            1;

        for (int second = m - 1;
             second >= 0;
             second--) {
            while (
                first >= 0 &&
                word1[first] !=
                word2[second]
            ) {
                first--;
            }

            if (first < 0) {
                suffix[second] =
                    -1;
            } else {
                suffix[second] =
                    first;

                first--;
            }
        }

        vector<int> answer;

        int second = 0;
        bool usedMismatch =
            false;

        for (int index = 0;
             index < n &&
             second < m;
             index++) {
            if (
                word1[index] ==
                word2[second]
            ) {
                answer.push_back(
                    index
                );

                second++;
            } else if (
                !usedMismatch &&
                (
                    second ==
                        m -
                        1 ||
                    (
                        suffix[second + 1] != -1 &&
                        index <
                        suffix[second + 1]
                    )
                )
            ) {
                answer.push_back(
                    index
                );

                second++;

                usedMismatch =
                    true;
            }
        }

        if (second != m) {
            return {};
        }

        return answer;
    }
};
