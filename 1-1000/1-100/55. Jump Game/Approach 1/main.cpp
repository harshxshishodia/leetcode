class Solution {
    bool solve(const vector<int>& nums, int index) {
        if (index >= nums.size() - 1)
            return true;

        int farthest = min(static_cast<int>(nums.size()) - 1, index + nums[index]);

        for (int nextIndex = index + 1; nextIndex <= farthest; nextIndex++) {
            if (solve(nums, nextIndex))
                return true;
        }

        return false;
    }

public:
    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }
};