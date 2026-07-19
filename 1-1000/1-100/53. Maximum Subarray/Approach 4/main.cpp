class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maximumSum = nums[0];

        for (int index = 1; index < nums.size(); index++) {
            currentSum = max(nums[index], currentSum + nums[index]);
            maximumSum = max(maximumSum, currentSum);
        }

        return maximumSum;
    }
};