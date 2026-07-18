class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<long long, pair<int, int>> pairBySum;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            for (int j = i + 1; j < static_cast<int>(nums.size()); ++j)
                pairBySum[static_cast<long long>(nums[i]) + nums[j]] = {i, j};
        auto it = pairBySum.find(target);
        if (it == pairBySum.end()) return {};
        return {it->second.first, it->second.second};
    }
};
