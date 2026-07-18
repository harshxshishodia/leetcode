// One-pass hash table: look for the complement before inserting the value.
// Time: O(n) expected, Space: O(n).
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = index.find(target - nums[i]);
            if (it != index.end()) {
                return {it->second, i};
            }
            index[nums[i]] = i;
        }

        return {};
    }
};
