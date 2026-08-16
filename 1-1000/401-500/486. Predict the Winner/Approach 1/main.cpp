class Solution {
    int solve(
        const vector<int>& nums,
        int left,
        int right
    ) {
        if (left == right) {
            return nums[left];
        }

        int takeLeft =
            nums[left] -
            solve(nums, left + 1, right);

        int takeRight =
            nums[right] -
            solve(nums, left, right - 1);

        return max(takeLeft, takeRight);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(
            nums,
            0,
            static_cast<int>(nums.size()) - 1
        ) >= 0;
    }
};
