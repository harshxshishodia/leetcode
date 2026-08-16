class Solution {
    int solve(const vector<int>& nums, int index) {
        if (index >= static_cast<int>(nums.size())) {
            return 0;
        }

        int skip = solve(nums, index + 1);
        int take = nums[index] + solve(nums, index + 2);

        return max(skip, take);
    }

public:
    int rob(vector<int>& nums) {
        return solve(nums, 0);
    }
};
