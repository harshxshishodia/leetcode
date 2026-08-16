class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        int answer = 0;

        for (int deleted = 0; deleted < n; deleted++) {
            int current = 0;
            int best = 0;

            for (int i = 0; i < n; i++) {
                if (i == deleted) {
                    continue;
                }

                if (nums[i] == 1) {
                    current++;
                    best = max(
                        best,
                        current
                    );
                } else {
                    current = 0;
                }
            }

            answer = max(
                answer,
                best
            );
        }

        return answer;
    }
};
