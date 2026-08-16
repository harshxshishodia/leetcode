class Solution {
    int solve(
        const vector<int>& nums,
        int index,
        bool previousTaken,
        bool firstTaken
    ) {
        int n = static_cast<int>(nums.size());

        if (index == n) {
            return 0;
        }

        int skip = solve(nums, index + 1, false, firstTaken);
        int take = 0;

        if (!previousTaken && !(index == n - 1 && firstTaken)) {
            take = nums[index] + solve(
                nums,
                index + 1,
                true,
                firstTaken || index == 0
            );
        }

        return max(skip, take);
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        return solve(nums, 0, false, false);
    }
};
