class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if (nums.size() <= 2) {
            return true;
        }

        for (int index = 1; index < static_cast<int>(nums.size()); index++) {
            if (nums[index - 1] + nums[index] >= m) {
                return true;
            }
        }

        return false;
    }
};
