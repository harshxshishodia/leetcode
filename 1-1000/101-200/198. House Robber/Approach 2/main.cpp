class Solution {
    int solve(const vector<int>& nums, int index, vector<int>& memo) {
        if (index >= static_cast<int>(nums.size())) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int skip = solve(nums, index + 1, memo);
        int take = nums[index] + solve(nums, index + 2, memo);

        memo[index] = max(skip, take);
        return memo[index];
    }

public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, 0, memo);
    }
};
