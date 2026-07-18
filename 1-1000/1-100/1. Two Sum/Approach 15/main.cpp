class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<pair<int, int>> seen;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = seen.lower_bound({target - nums[i], INT_MIN});
            if (it != seen.end() && it->first == target - nums[i])
                return {it->second, i};
            seen.emplace(nums[i], i);
        }
        return {};
    }
};
