class Solution {
    bool compatible(
        const string& first,
        const string& second
    ) {
        if (first.size() !=
            second.size()) {
            return false;
        }

        int differences = 0;

        for (int position = 0;
             position < static_cast<int>(first.size());
             position++) {
            differences +=
                first[position] !=
                second[position];

            if (differences > 1) {
                return false;
            }
        }

        return differences == 1;
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

        int bestEnd = 0;

        for (int index = 0;
             index < n;
             index++) {
            for (int previous = 0;
                 previous < index;
                 previous++) {
                if (groups[previous] ==
                    groups[index]) {
                    continue;
                }

                if (!compatible(
                        words[previous],
                        words[index])) {
                    continue;
                }

                if (dp[previous] + 1 >
                    dp[index]) {
                    dp[index] =
                        dp[previous] +
                        1;

                    parent[index] =
                        previous;
                }
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
