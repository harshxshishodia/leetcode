class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        vector<int> left(n);
        vector<int> right(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                left[i] =
                    1 +
                    (
                        i > 0
                            ? left[i - 1]
                            : 0
                    );
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 1) {
                right[i] =
                    1 +
                    (
                        i + 1 < n
                            ? right[i + 1]
                            : 0
                    );
            }
        }

        int answer = 0;

        for (int deleted = 0; deleted < n; deleted++) {
            int before =
                deleted > 0
                    ? left[deleted - 1]
                    : 0;

            int after =
                deleted + 1 < n
                    ? right[deleted + 1]
                    : 0;

            answer = max(
                answer,
                before + after
            );
        }

        return answer;
    }
};
