class Solution {
    int solve(
        const vector<int>& nums,
        int index,
        int previousIndex,
        int direction
    ) {
        if (index == static_cast<int>(nums.size())) {
            return 0;
        }

        int skip = solve(
            nums,
            index + 1,
            previousIndex,
            direction
        );

        int take = 0;

        if (previousIndex == -1) {
            take = 1 + solve(
                nums,
                index + 1,
                index,
                0
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
                    1
                );
            } else if (difference < 0 && direction != 2) {
                take = 1 + solve(
                    nums,
                    index + 1,
                    index,
                    2
                );
            }
        }

        return max(skip, take);
    }

public:
    int wiggleMaxLength(vector<int>& nums) {
        return solve(nums, 0, -1, 0);
    }
};
