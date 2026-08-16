class Solution {
    struct TopTwo {
        int first = -1;
        int second = -1;
    };

    void addCandidate(
        TopTwo& top,
        int index,
        const vector<int>& groups,
        const vector<int>& dp
    ) {
        if (top.first != -1 &&
            groups[top.first] ==
            groups[index]) {
            if (dp[index] >
                dp[top.first]) {
                top.first =
                    index;
            }

            return;
        }

        if (top.second != -1 &&
            groups[top.second] ==
            groups[index]) {
            if (dp[index] >
                dp[top.second]) {
                top.second =
                    index;
            }

            if (top.first != -1 &&
                dp[top.second] >
                dp[top.first]) {
                swap(
                    top.first,
                    top.second
                );
            }

            return;
        }

        if (top.first == -1 ||
            dp[index] >
            dp[top.first]) {
            top.second =
                top.first;

            top.first =
                index;
        } else if (
            top.second == -1 ||
            dp[index] >
            dp[top.second]
        ) {
            top.second =
                index;
        }
    }

    int bestCandidate(
        const TopTwo& top,
        int group,
        const vector<int>& groups
    ) {
        if (top.first != -1 &&
            groups[top.first] != group) {
            return top.first;
        }

        if (top.second != -1 &&
            groups[top.second] != group) {
            return top.second;
        }

        return -1;
    }

    string makeKey(
        const string& word,
        int position
    ) {
        return
            to_string(
                word.size()
            ) +
            ":" +
            to_string(
                position
            ) +
            ":" +
            word.substr(
                0,
                position
            ) +
            "#" +
            word.substr(
                position + 1
            );
    }

public:
    vector<string> getWordsInLongestSubsequence(
        vector<string>& words,
        vector<int>& groups
    ) {
        int n =
            static_cast<int>(words.size());

        vector<int> dp(
            n,
            1
        );

        vector<int> parent(
            n,
            -1
        );

        unordered_map<
            string,
            array<TopTwo, 26>
        > table;

        int bestEnd = 0;

        for (int index = 0;
             index < n;
             index++) {
            int bestLength = 1;
            int bestParent = -1;

            for (int position = 0;
                 position < static_cast<int>(words[index].size());
                 position++) {
                string key =
                    makeKey(
                        words[index],
                        position
                    );

                auto found =
                    table.find(key);

                if (found == table.end()) {
                    continue;
                }

                int currentCharacter =
                    words[index][position] -
                    'a';

                for (int character = 0;
                     character < 26;
                     character++) {
                    if (character ==
                        currentCharacter) {
                        continue;
                    }

                    int candidate =
                        bestCandidate(
                            found->second[character],
                            groups[index],
                            groups
                        );

                    if (candidate != -1 &&
                        dp[candidate] + 1 >
                        bestLength) {
                        bestLength =
                            dp[candidate] +
                            1;

                        bestParent =
                            candidate;
                    }
                }
            }

            dp[index] =
                bestLength;

            parent[index] =
                bestParent;

            for (int position = 0;
                 position < static_cast<int>(words[index].size());
                 position++) {
                string key =
                    makeKey(
                        words[index],
                        position
                    );

                int character =
                    words[index][position] -
                    'a';

                addCandidate(
                    table[key][character],
                    index,
                    groups,
                    dp
                );
            }

            if (dp[index] >
                dp[bestEnd]) {
                bestEnd =
                    index;
            }
        }

        vector<string> answer;

        for (int index = bestEnd;
             index != -1;
             index = parent[index]) {
            answer.push_back(
                words[index]
            );
        }

        reverse(
            answer.begin(),
            answer.end()
        );

        return answer;
    }
};
