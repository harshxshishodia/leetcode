class Solution {
    int solve(
        const vector<int>& nums,
        int index,
        int remainder,
        vector<vector<int>>& memo
    ) {
        if (index == static_cast<int>(nums.size())) {
            return remainder == 0
                ? 0
                : -1000000000;
        }

        if (memo[index][remainder] != -1000000001) {
            return memo[index][remainder];
        }

        int skip = solve(
            nums,
            index + 1,
            remainder,
            memo
        );

        int take =
            nums[index] +
            solve(
                nums,
                index + 1,
                (
                    remainder -
                    nums[index] % 3 +
                    3
                ) %
                3,
                memo
            );

        memo[index][remainder] = max(
            skip,
            take
        );

        return memo[index][remainder];
    }

public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> memo(
            nums.size(),
            vector<int>(
                3,
                -1000000001
            )
        );

        return max(
            0,
            solve(
                nums,
                0,
                0,
                memo
            )
        );
    }
};
