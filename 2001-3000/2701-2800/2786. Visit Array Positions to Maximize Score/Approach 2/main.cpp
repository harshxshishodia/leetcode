class Solution {
    vector<array<long long, 2>> memo;
    vector<array<bool, 2>> visited;

    long long solve(const vector<int>& nums, int x, int index, int parity) {
        if (index == static_cast<int>(nums.size())) {
            return 0;
        }

        if (visited[index][parity]) {
            return memo[index][parity];
        }

        visited[index][parity] = true;

        long long skip = solve(nums, x, index + 1, parity);
        int currentParity = nums[index] & 1;
        long long take =
            nums[index] -
            (currentParity != parity ? x : 0) +
            solve(nums, x, index + 1, currentParity);

        memo[index][parity] = max(skip, take);
        return memo[index][parity];
    }

public:
    long long maxScore(vector<int>& nums, int x) {
        memo.assign(nums.size(), {});
        visited.assign(nums.size(), {});

        return nums[0] + solve(nums, x, 1, nums[0] & 1);
    }
};
