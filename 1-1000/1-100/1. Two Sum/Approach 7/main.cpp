class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> values;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            values.emplace_back(nums[i], i);
        sort(values.begin(), values.end());
        for (int i = 0; i < static_cast<int>(values.size()); ++i) {
            long long need = static_cast<long long>(target) - values[i].first;
            if (need < INT_MIN || need > INT_MAX) continue;
            auto it = lower_bound(
                values.begin() + i + 1,
                values.end(),
                make_pair(static_cast<int>(need), INT_MIN)
            );
            if (it != values.end() && it->first == need)
                return {values[i].second, it->second};
        }
        return {};
    }
};
