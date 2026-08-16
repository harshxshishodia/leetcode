class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int firstLength =
            static_cast<int>(nums1.size());

        int secondLength =
            static_cast<int>(nums2.size());

        vector<vector<int>> dp(
            firstLength + 1,
            vector<int>(secondLength + 1)
        );

        int answer = 0;

        for (int i = firstLength - 1; i >= 0; i--) {
            for (int j = secondLength - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] =
                        1 + dp[i + 1][j + 1];

                    answer = max(
                        answer,
                        dp[i][j]
                    );
                }
            }
        }

        return answer;
    }
};
