class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<long long, array<int, 2>> sums;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            for (int j = i + 1; j < static_cast<int>(nums.size()); ++j)
                sums.emplace(
                    static_cast<long long>(nums[i]) + nums[j],
                    array<int, 2>{i, j}
                );
        auto it = sums.find(target);
        if (it == sums.end()) return {};
        return {it->second[0], it->second[1]};
    }
};
