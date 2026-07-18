class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int> positions;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            positions.emplace(nums[i], i);
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto range = positions.equal_range(target - nums[i]);
            for (auto it = range.first; it != range.second; ++it)
                if (it->second != i) return {i, it->second};
        }
        return {};
    }
};
