class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long answer =
            nums[0];

        for (int index = 1;
             index < static_cast<int>(nums.size());
             index++) {
            if (nums[index] > nums[index - 1]) {
                answer +=
                    nums[index] -
                    nums[index - 1];
            }
        }

        return answer;
    }
};
