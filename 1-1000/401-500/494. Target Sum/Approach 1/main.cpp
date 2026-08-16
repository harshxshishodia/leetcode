class Solution {
    int solve(
        const vector<int>& nums,
        int index,
        int current,
        int target
    ) {
        if (index == static_cast<int>(nums.size())) {
            return current == target ? 1 : 0;
        }

        return
            solve(
                nums,
                index + 1,
                current + nums[index],
                target
            ) +
            solve(
                nums,
                index + 1,
                current - nums[index],
                target
            );
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, 0, target);
    }
};
