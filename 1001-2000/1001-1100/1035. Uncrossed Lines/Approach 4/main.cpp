class Solution {
public:
    int maxUncrossedLines(
        vector<int>& nums1,
        vector<int>& nums2
    ) {
        if (nums1.size() < nums2.size()) {
            swap(
                nums1,
                nums2
            );
        }

        int firstLength =
            static_cast<int>(nums1.size());

        int secondLength =
            static_cast<int>(nums2.size());

        vector<int> dp(
            secondLength + 1
        );

        for (int i = 1; i <= firstLength; i++) {
            int diagonal = 0;

            for (int j = 1; j <= secondLength; j++) {
                int fromTop =
                    dp[j];

                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] =
                        diagonal + 1;
                } else {
                    dp[j] = max(
                        dp[j],
                        dp[j - 1]
                    );
                }

                diagonal =
                    fromTop;
            }
        }

        return dp[secondLength];
    }
};
