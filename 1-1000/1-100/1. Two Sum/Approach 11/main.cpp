class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            positions[nums[i]].push_back(i);
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = positions.find(target - nums[i]);
            if (it == positions.end()) continue;
            for (int j : it->second)
                if (j != i) return {i, j};
        }
        return {};
    }
};
