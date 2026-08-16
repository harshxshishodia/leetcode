class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int answer = 0;

        for (int left = 0; left < n; left++) {
            int sign = 1;

            for (int right = left; right < n; right++) {
                if (nums[right] == 0) {
                    break;
                }

                if (nums[right] < 0) {
                    sign *= -1;
                }

                if (sign > 0) {
                    answer = max(
                        answer,
                        right - left + 1
                    );
                }
            }
        }

        return answer;
    }
};
