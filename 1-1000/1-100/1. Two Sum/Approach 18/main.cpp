class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> firstIndex;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            firstIndex.emplace(nums[i], i);
        for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i) {
            auto it = firstIndex.find(target - nums[i]);
            if (it != firstIndex.end() && it->second != i)
                return {it->second, i};
        }
        return {};
    }
};
