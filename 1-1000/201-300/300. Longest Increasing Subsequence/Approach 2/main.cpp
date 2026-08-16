class Solution {
    int solve(
        const vector<int>& nums,
        int index,
        int previousIndex,
        vector<vector<int>>& memo
    ) {
        if (index == static_cast<int>(nums.size())) {
            return 0;
        }

        int previousState = previousIndex + 1;

        if (memo[index][previousState] != -1) {
            return memo[index][previousState];
        }

        int skip = solve(
            nums,
            index + 1,
            previousIndex,
            memo
        );

        int take = 0;

        if (previousIndex == -1 ||
            nums[index] > nums[previousIndex]) {
            take = 1 + solve(
                nums,
                index + 1,
                index,
                memo
            );
        }

        memo[index][previousState] = max(skip, take);
        return memo[index][previousState];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<vector<int>> memo(
            n,
            vector<int>(n + 1, -1)
        );

        return solve(nums, 0, -1, memo);
    }
};
