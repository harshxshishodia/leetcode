class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        if (s2.size() > s1.size()) {
            swap(s1, s2);
        }

        int firstLength = static_cast<int>(s1.size());
        int secondLength = static_cast<int>(s2.size());
        vector<bool> dp(secondLength + 1);
        dp[0] = true;

        for (int j = 1; j <= secondLength; j++) {
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= firstLength; i++) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];

            for (int j = 1; j <= secondLength; j++) {
                bool fromFirst = dp[j] &&
                                 s1[i - 1] == s3[i + j - 1];
                bool fromSecond = dp[j - 1] &&
                                  s2[j - 1] == s3[i + j - 1];
                dp[j] = fromFirst || fromSecond;
            }
        }

        return dp[secondLength];
    }
};
