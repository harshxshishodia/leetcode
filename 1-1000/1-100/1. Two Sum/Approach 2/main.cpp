class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> position;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            position[nums[i]] = i;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = position.find(target - nums[i]);
            if (it != position.end() && it->second != i)
                return {i, it->second};
        }
        return {};
    }
};
