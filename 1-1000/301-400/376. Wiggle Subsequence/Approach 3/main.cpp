class Solution {
    int solve(
        const vector<int>& nums,
        int index,
        int previousIndex,
        int direction,
        vector<vector<array<int, 3>>>& memo
    ) {
        if (index == static_cast<int>(nums.size())) {
            return 0;
        }

        int previousState = previousIndex + 1;

        if (memo[index][previousState][direction] != -1) {
            return memo[index][previousState][direction];
        }

        int skip = solve(
            nums,
            index + 1,
            previousIndex,
            direction,
            memo
        );

        int take = 0;

        if (previousIndex == -1) {
            take = 1 + solve(
                nums,
                index + 1,
                index,
                0,
                memo
            );
        } else {
            long long difference =
                static_cast<long long>(nums[index]) -
                nums[previousIndex];

            if (difference > 0 && direction != 1) {
                take = 1 + solve(
                    nums,
                    index + 1,
                    index,
                    1,
                    memo
                );
            } else if (difference < 0 && direction != 2) {
                take = 1 + solve(
                    nums,
                    index + 1,
                    index,
                    2,
                    memo
                );
            }
        }

        memo[index][previousState][direction] = max(skip, take);
        return memo[index][previousState][direction];
    }

public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<vector<array<int, 3>>> memo(
            n,
            vector<array<int, 3>>(n + 1)
        );

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                memo[i][j].fill(-1);
            }
        }

        return solve(nums, 0, -1, 0, memo);
    }
};
