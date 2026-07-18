class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = find(nums.begin() + i + 1, nums.end(), target - nums[i]);
            if (it != nums.end())
                return {i, static_cast<int>(it - nums.begin())};
        }
        return {};
    }
};
