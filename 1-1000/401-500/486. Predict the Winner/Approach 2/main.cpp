class Solution {
    int solve(
        const vector<int>& nums,
        int left,
        int right,
        vector<vector<int>>& memo
    ) {
        if (left == right) {
            return nums[left];
        }

        if (memo[left][right] != numeric_limits<int>::min()) {
            return memo[left][right];
        }

        int takeLeft =
            nums[left] -
            solve(nums, left + 1, right, memo);

        int takeRight =
            nums[right] -
            solve(nums, left, right - 1, memo);

        memo[left][right] = max(takeLeft, takeRight);
        return memo[left][right];
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        vector<vector<int>> memo(
            n,
            vector<int>(
                n,
                numeric_limits<int>::min()
            )
        );

        return solve(nums, 0, n - 1, memo) >= 0;
    }
};
