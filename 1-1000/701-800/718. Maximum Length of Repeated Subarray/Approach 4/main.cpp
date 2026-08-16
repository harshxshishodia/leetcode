class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            swap(nums1, nums2);
        }

        int firstLength =
            static_cast<int>(nums1.size());

        int secondLength =
            static_cast<int>(nums2.size());

        vector<int> dp(secondLength + 1);
        int answer = 0;

        for (int i = firstLength - 1; i >= 0; i--) {
            for (int j = 0; j < secondLength; j++) {
                if (nums1[i] == nums2[j]) {
                    dp[j] =
                        1 + dp[j + 1];

                    answer = max(
                        answer,
                        dp[j]
                    );
                } else {
                    dp[j] = 0;
                }
            }
        }

        return answer;
    }
};
