// Two-pass hash table: store all indices, then look up each complement.
// Time: O(n) expected, Space: O(n).
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            index[nums[i]] = i;
        }

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = index.find(target - nums[i]);
            if (it != index.end() && it->second != i) {
                return {i, it->second};
            }
        }

        return {};
    }
};
