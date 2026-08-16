class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zeroes = 0;
        int answer = 0;

        for (int right = 0;
             right < static_cast<int>(nums.size());
             right++) {
            zeroes +=
                nums[right] == 0;

            while (zeroes > 1) {
                zeroes -=
                    nums[left] == 0;

                left++;
            }

            answer = max(
                answer,
                right - left
            );
        }

        return answer;
    }
};
