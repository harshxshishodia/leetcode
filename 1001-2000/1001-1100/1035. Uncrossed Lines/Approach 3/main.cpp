class Solution {
public:
    int maxUncrossedLines(
        vector<int>& nums1,
        vector<int>& nums2
    ) {
        int firstLength =
            static_cast<int>(nums1.size());

        int secondLength =
            static_cast<int>(nums2.size());

        vector<vector<int>> dp(
            firstLength + 1,
            vector<int>(
                secondLength + 1
            )
        );

        for (int i = 1; i <= firstLength; i++) {
            for (int j = 1; j <= secondLength; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] =
                        1 +
                        dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
                }
            }
        }

        return dp[firstLength][secondLength];
    }
};
