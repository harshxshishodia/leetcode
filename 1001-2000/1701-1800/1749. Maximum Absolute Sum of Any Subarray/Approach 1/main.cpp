class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int answer = 0;

        for (int left = 0;
             left < static_cast<int>(nums.size());
             left++) {
            int sum = 0;

            for (int right = left;
                 right < static_cast<int>(nums.size());
                 right++) {
                sum += nums[right];

                answer = max(
                    answer,
                    abs(sum)
                );
            }
        }

        return answer;
    }
};
