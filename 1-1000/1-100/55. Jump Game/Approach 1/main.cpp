class Solution {
    bool solve(const vector<int>& nums, int index) {
        if (index >= static_cast<int>(nums.size()) - 1) {
            return true;
        }

        int furthest = min(
            static_cast<int>(nums.size()) - 1,
            index + nums[index]
        );

        for (int next = index + 1; next <= furthest; next++) {
            if (solve(nums, next)) {
                return true;
            }
        }

        return false;
    }

public:
    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }
};
