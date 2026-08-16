class Solution {
    int solve(
        const vector<int>& nums,
        int index,
        int previousTaken,
        int firstTaken,
        vector<vector<vector<int>>>& memo
    ) {
        int n = static_cast<int>(nums.size());

        if (index == n) {
            return 0;
        }

        if (memo[index][previousTaken][firstTaken] != -1) {
            return memo[index][previousTaken][firstTaken];
        }

        int skip = solve(
            nums,
            index + 1,
            0,
            firstTaken,
            memo
        );

        int take = 0;

        if (previousTaken == 0 &&
            !(index == n - 1 && firstTaken == 1)) {
            take = nums[index] + solve(
                nums,
                index + 1,
                1,
                firstTaken == 1 || index == 0,
                memo
            );
        }

        memo[index][previousTaken][firstTaken] = max(skip, take);
        return memo[index][previousTaken][firstTaken];
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<vector<vector<int>>> memo(
            nums.size(),
            vector<vector<int>>(2, vector<int>(2, -1))
        );

        return solve(nums, 0, 0, 0, memo);
    }
};
