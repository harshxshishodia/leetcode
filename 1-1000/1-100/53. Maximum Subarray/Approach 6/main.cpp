class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = nums[0];
        int answer = nums[0];

        for (int i = 1; i < static_cast<int>(nums.size()); i++) {
            current = max(nums[i], current + nums[i]);
            answer = max(answer, current);
        }

        return answer;
    }
};
