class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        if (s1.size() < s2.size()) {
            swap(s1, s2);
        }

        int firstLength = static_cast<int>(s1.size());
        int secondLength = static_cast<int>(s2.size());

        vector<int> dp(secondLength + 1);

        for (int j = 1; j <= secondLength; j++) {
            dp[j] =
                dp[j - 1] +
                static_cast<unsigned char>(s2[j - 1]);
        }

        for (int i = 1; i <= firstLength; i++) {
            int diagonal = dp[0];

            dp[0] +=
                static_cast<unsigned char>(s1[i - 1]);

            for (int j = 1; j <= secondLength; j++) {
                int fromTop = dp[j];

                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = diagonal;
                } else {
                    dp[j] = min(
                        fromTop +
                        static_cast<unsigned char>(s1[i - 1]),
                        dp[j - 1] +
                        static_cast<unsigned char>(s2[j - 1])
                    );
                }

                diagonal = fromTop;
            }
        }

        return dp[secondLength];
    }
};
