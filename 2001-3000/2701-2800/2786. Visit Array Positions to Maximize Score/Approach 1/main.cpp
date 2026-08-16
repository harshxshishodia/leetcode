class Solution {
    long long solve(const vector<int>& nums, int x, int index, int parity) {
        if (index == static_cast<int>(nums.size())) {
            return 0;
        }

        long long skip = solve(nums, x, index + 1, parity);
        int currentParity = nums[index] & 1;
        long long take =
            nums[index] -
            (currentParity != parity ? x : 0) +
            solve(nums, x, index + 1, currentParity);

        return max(skip, take);
    }

public:
    long long maxScore(vector<int>& nums, int x) {
        return nums[0] + solve(nums, x, 1, nums[0] & 1);
    }
};
