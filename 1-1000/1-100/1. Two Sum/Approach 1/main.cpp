class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            for (int j = i + 1; j < static_cast<int>(nums.size()); ++j)
                if (static_cast<long long>(nums[i]) + nums[j] == target)
                    return {i, j};
        return {};
    }
};
