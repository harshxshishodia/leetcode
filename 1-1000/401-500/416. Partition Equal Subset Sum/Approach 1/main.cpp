class Solution {
    bool solve(
        const vector<int>& nums,
        int index,
        int target
    ) {
        if (target == 0) {
            return true;
        }

        if (index == static_cast<int>(nums.size()) ||
            target < 0) {
            return false;
        }

        return solve(nums, index + 1, target) ||
               solve(nums, index + 1, target - nums[index]);
    }

public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0) {
            return false;
        }

        return solve(nums, 0, total / 2);
    }
};
