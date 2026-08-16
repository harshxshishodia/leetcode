class Solution {
    int solve(
        const vector<int>& nums,
        int index,
        int target,
        vector<vector<int>>& memo
    ) {
        if (target == 0) {
            return 1;
        }

        if (index == static_cast<int>(nums.size()) ||
            target < 0) {
            return 0;
        }

        if (memo[index][target] != -1) {
            return memo[index][target];
        }

        bool possible = solve(
            nums,
            index + 1,
            target,
            memo
        );

        if (!possible && nums[index] <= target) {
            possible = solve(
                nums,
                index + 1,
                target - nums[index],
                memo
            );
        }

        memo[index][target] = possible;
        return memo[index][target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0) {
            return false;
        }

        int target = total / 2;
        vector<vector<int>> memo(
            nums.size(),
            vector<int>(target + 1, -1)
        );

        return solve(nums, 0, target, memo);
    }
};
