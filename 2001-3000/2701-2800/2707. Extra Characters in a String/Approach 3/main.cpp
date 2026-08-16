class Solution {
public:
    int minExtraChar(
        string s,
        vector<string>& dictionary
    ) {
        unordered_set<string> words(
            dictionary.begin(),
            dictionary.end()
        );

        int n =
            static_cast<int>(s.size());

        vector<int> dp(
            n + 1
        );

        for (int index = n - 1;
             index >= 0;
             index--) {
            dp[index] =
                1 +
                dp[index + 1];

            string current;

            for (int end = index;
                 end < n;
                 end++) {
                current.push_back(
                    s[end]
                );

                if (words.count(current)) {
                    dp[index] = min(
                        dp[index],
                        dp[end + 1]
                    );
                }
            }
        }

        return dp[0];
    }
};
