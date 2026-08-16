class Solution {
public:
    int minimumCost(
        string sentence,
        int k
    ) {
        vector<string> words;

        stringstream stream(sentence);
        string word;

        while (stream >> word) {
            words.push_back(word);
        }

        int n =
            static_cast<int>(words.size());

        vector<int> dp(
            n + 1,
            0
        );

        for (int index = n - 1;
             index >= 0;
             index--) {
            int length = 0;

            dp[index] =
                numeric_limits<int>::max();

            for (int end = index;
                 end < n;
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
                    end == n - 1
                        ? 0
                        : (k - length) *
                          (k - length);

                dp[index] = min(
                    dp[index],
                    cost +
                    dp[end + 1]
                );
            }
        }

        return dp[0];
    }
};
