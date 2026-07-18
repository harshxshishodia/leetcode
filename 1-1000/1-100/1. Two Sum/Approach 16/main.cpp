class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> seen;
        int firstValue = 0, secondValue = 0;
        for (int value : nums) {
            if (seen.count(target - value)) {
                firstValue = target - value;
                secondValue = value;
                break;
            }
            seen.insert(value);
        }
        int first = -1;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            if (nums[i] == firstValue) {
                first = i;
                break;
            }
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            if (i != first && nums[i] == secondValue) return {first, i};
        return {};
    }
};
