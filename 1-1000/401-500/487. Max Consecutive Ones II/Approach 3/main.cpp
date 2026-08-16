class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int zeroes = 0;
        int answer = 0;

        for (int right = 0;
             right < static_cast<int>(nums.size());
             right++) {
            if (nums[right] == 0) {
                zeroes++;
            }

            while (zeroes > 1) {
                if (nums[left] == 0) {
                    zeroes--;
                }

                left++;
            }

            answer = max(
                answer,
                right - left + 1
            );
        }

        return answer;
    }
};
