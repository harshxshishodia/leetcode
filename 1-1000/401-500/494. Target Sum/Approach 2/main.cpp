class Solution {
    int solve(
        const vector<int>& nums,
        int index,
        int current,
        int target,
        int offset,
        vector<vector<int>>& memo
    ) {
        if (index == static_cast<int>(nums.size())) {
            return current == target ? 1 : 0;
        }

        int state = current + offset;

        if (memo[index][state] != -1) {
            return memo[index][state];
        }

        memo[index][state] =
            solve(
                nums,
                index + 1,
                current + nums[index],
                target,
                offset,
                memo
            ) +
            solve(
                nums,
                index + 1,
                current - nums[index],
                target,
                offset,
                memo
            );

        return memo[index][state];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(
            nums.begin(),
            nums.end(),
            0
        );

        vector<vector<int>> memo(
            nums.size(),
            vector<int>(2 * total + 1, -1)
        );

        return solve(
            nums,
            0,
            0,
            target,
            total,
            memo
        );
    }
};
