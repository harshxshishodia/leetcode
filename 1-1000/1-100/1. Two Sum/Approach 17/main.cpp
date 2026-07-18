class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        list<pair<int, int>> values;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            values.emplace_back(nums[i], i);
        values.sort();
        auto left = values.begin();
        auto right = prev(values.end());
        while (left != right) {
            long long sum = static_cast<long long>(left->first) + right->first;
            if (sum == target) return {left->second, right->second};
            if (sum < target) ++left;
            else --right;
        }
        return {};
    }
};
