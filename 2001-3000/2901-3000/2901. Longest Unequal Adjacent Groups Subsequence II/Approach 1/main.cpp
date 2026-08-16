class Solution {
    vector<int> best;

    bool valid(
        const vector<string>& words,
        const vector<int>& groups,
        const vector<int>& chosen
    ) {
        for (int index = 1;
             index < static_cast<int>(chosen.size());
             index++) {
            int first =
                chosen[index - 1];

            int second =
                chosen[index];

            if (groups[first] ==
                groups[second]) {
                return false;
            }

            if (words[first].size() !=
                words[second].size()) {
                return false;
            }

            int differences = 0;

            for (int position = 0;
                 position < static_cast<int>(words[first].size());
                 position++) {
                differences +=
                    words[first][position] !=
                    words[second][position];
            }

            if (differences != 1) {
                return false;
            }
        }

        return true;
    }

    void search(
        const vector<string>& words,
        const vector<int>& groups,
        int index,
        vector<int>& chosen
    ) {
        if (index ==
            static_cast<int>(words.size())) {
            if (chosen.size() >
                    best.size() &&
                valid(
                    words,
                    groups,
                    chosen
                )) {
                best =
                    chosen;
            }

            return;
        }

        search(
            words,
            groups,
            index + 1,
            chosen
        );

        chosen.push_back(index);

        search(
            words,
            groups,
            index + 1,
            chosen
        );

        chosen.pop_back();
    }

public:
    vector<string> getWordsInLongestSubsequence(
        vector<string>& words,
        vector<int>& groups
    ) {
        best.clear();

        vector<int> chosen;

        search(
            words,
            groups,
            0,
            chosen
        );

        vector<string> answer;

        for (int index : best) {
            answer.push_back(
                words[index]
            );
        }

        return answer;
    }
};
