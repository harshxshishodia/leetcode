class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> order(nums.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        int left = 0, right = static_cast<int>(order.size()) - 1;
        while (left < right) {
            long long sum = static_cast<long long>(nums[order[left]]) + nums[order[right]];
            if (sum == target) return {order[left], order[right]};
            if (sum < target) ++left;
            else --right;
        }
        return {};
    }
};
