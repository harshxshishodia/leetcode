class Solution {
public:
    int minValidStrings(
        vector<string>& words,
        string target
    ) {
        unordered_set<string> valid;

        for (const string& word :
             words) {
            string prefix;

            for (char character :
                 word) {
                prefix.push_back(
                    character
                );

                valid.insert(
                    prefix
                );
            }
        }

        int n =
            static_cast<int>(target.size());

        const int INF =
            1000000000;

        vector<int> dp(
            n + 1,
            INF
        );

        dp[0] =
            0;

        for (int index = 0;
             index < n;
             index++) {
            if (dp[index] == INF) {
                continue;
            }

            string current;

            for (int end = index;
                 end < n;
                 end++) {
                current.push_back(
                    target[end]
                );

                if (!valid.count(current)) {
                    continue;
                }

                dp[end + 1] = min(
                    dp[end + 1],
                    dp[index] +
                    1
                );
            }
        }

        return dp[n] == INF
            ? -1
            : dp[n];
    }
};
