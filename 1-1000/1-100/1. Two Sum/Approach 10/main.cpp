class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> expected;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = expected.find(nums[i]);
            if (it != expected.end()) return {it->second, i};
            expected[target - nums[i]] = i;
        }
        return {};
    }
};
