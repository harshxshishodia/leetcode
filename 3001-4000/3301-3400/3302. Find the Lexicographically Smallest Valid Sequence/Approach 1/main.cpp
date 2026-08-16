class Solution {
    vector<int> answer;

    bool almostEqual(
        const string& word1,
        const string& word2,
        const vector<int>& chosen
    ) {
        if (chosen.size() !=
            word2.size()) {
            return false;
        }

        int differences = 0;

        for (int index = 0;
             index < static_cast<int>(word2.size());
             index++) {
            differences +=
                word1[chosen[index]] !=
                word2[index];

            if (differences > 1) {
                return false;
            }
        }

        return true;
    }

    bool search(
        const string& word1,
        const string& word2,
        int index,
        vector<int>& chosen
    ) {
        if (chosen.size() ==
            word2.size()) {
            if (almostEqual(
                    word1,
                    word2,
                    chosen)) {
                answer =
                    chosen;

                return true;
            }

            return false;
        }

        int needed =
            static_cast<int>(
                word2.size() -
                chosen.size()
            );

        if (
            static_cast<int>(word1.size()) -
            index <
            needed
        ) {
            return false;
        }

        for (int current = index;
             current < static_cast<int>(word1.size());
             current++) {
            chosen.push_back(
                current
            );

            if (search(
                    word1,
                    word2,
                    current + 1,
                    chosen)) {
                return true;
            }

            chosen.pop_back();
        }

        return false;
    }

public:
    vector<int> validSequence(
        string word1,
        string word2
    ) {
        answer.clear();

        vector<int> chosen;

        search(
            word1,
            word2,
            0,
            chosen
        );

        return answer;
    }
};
