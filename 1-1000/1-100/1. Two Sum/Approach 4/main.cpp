class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> values;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            values.push_back({nums[i], i});
        sort(values.begin(), values.end());
        int left = 0, right = static_cast<int>(values.size()) - 1;
        while (left < right) {
            long long sum = static_cast<long long>(values[left].first) + values[right].first;
            if (sum == target) return {values[left].second, values[right].second};
            if (sum < target) ++left;
            else --right;
        }
        return {};
    }
};
