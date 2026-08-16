class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long length = 0;
        long long answer = 0;

        for (int index = 0;
             index < static_cast<int>(nums.size());
             index++) {
            if (index > 0 &&
                nums[index] >
                nums[index - 1]) {
                length++;
            } else {
                length = 1;
            }

            answer +=
                length;
        }

        return answer;
    }
};
