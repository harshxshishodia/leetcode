class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        seen.reserve(nums.size() * 2);
        seen.max_load_factor(0.7f);
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto [it, found] = seen.try_emplace(target - nums[i], -1);
            if (found) {
                seen.erase(it);
                seen.emplace(nums[i], i);
            } else if (it->second >= 0) {
                return {it->second, i};
            } else {
                seen.erase(it);
                seen.emplace(nums[i], i);
            }
        }
        return {};
    }
};
