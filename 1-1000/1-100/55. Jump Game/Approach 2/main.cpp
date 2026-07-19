class Solution {
    vector<int> memo;

    bool solve(const vector<int>& nums, int index) {
        if (index >= nums.size() - 1)
            return true;

        if (memo[index] != -1)
            return memo[index];

        int farthest = min(static_cast<int>(nums.size()) - 1, index + nums[index]);

        for (int nextIndex = index + 1; nextIndex <= farthest; nextIndex++) {
            if (solve(nums, nextIndex))
                return memo[index] = true;
        }

        return memo[index] = false;
    }

public:
    bool canJump(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        return solve(nums, 0);
    }
};