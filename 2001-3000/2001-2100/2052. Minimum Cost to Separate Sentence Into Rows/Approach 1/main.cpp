class Solution {
    vector<string> words;

    int solve(
        int index,
        int k
    ) {
        if (index ==
            static_cast<int>(words.size())) {
            return 0;
        }

        int length = 0;
        int answer =
            numeric_limits<int>::max();

        for (int end = index;
             end < static_cast<int>(words.size());
             end++) {
            if (end > index) {
                length++;
            }

            length +=
                static_cast<int>(words[end].size());

            if (length > k) {
                break;
            }

            int cost =
                end ==
                static_cast<int>(words.size()) - 1
                    ? 0
                    : (k - length) *
                      (k - length);

            answer = min(
                answer,
                cost +
                solve(
                    end + 1,
                    k
                )
            );
        }

        return answer;
    }

public:
    int minimumCost(
        string sentence,
        int k
    ) {
        words.clear();

        stringstream stream(sentence);
        string word;

        while (stream >> word) {
            words.push_back(word);
        }

        return solve(
            0,
            k
        );
    }
};
