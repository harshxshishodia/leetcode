class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int left = 0, right = static_cast<int>(sorted.size()) - 1;
        while (left < right) {
            long long sum = static_cast<long long>(sorted[left]) + sorted[right];
            if (sum == target) break;
            if (sum < target) ++left;
            else --right;
        }
        int first = -1;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            if (nums[i] == sorted[left]) {
                first = i;
                break;
            }
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            if (i != first && nums[i] == sorted[right]) return {first, i};
        return {};
    }
};
