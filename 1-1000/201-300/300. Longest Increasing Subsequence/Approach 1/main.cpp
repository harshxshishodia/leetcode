class Solution {
    int solve(
        const vector<int>& nums,
        int index,
        int previousIndex
    ) {
        if (index == static_cast<int>(nums.size())) {
            return 0;
        }

        int skip = solve(nums, index + 1, previousIndex);
        int take = 0;

        if (previousIndex == -1 ||
            nums[index] > nums[previousIndex]) {
            take = 1 + solve(nums, index + 1, index);
        }

        return max(skip, take);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, -1);
    }
};
