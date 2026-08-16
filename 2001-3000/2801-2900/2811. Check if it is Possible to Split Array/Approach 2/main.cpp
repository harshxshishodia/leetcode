class Solution {
    vector<long long> prefix;
    vector<vector<int>> memo;
    int m;

    long long rangeSum(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }

    int solve(int left, int right) {
        if (right - left + 1 <= 2) {
            return 1;
        }

        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        for (int split = left; split < right; split++) {
            int leftLength = split - left + 1;
            int rightLength = right - split;

            bool leftAllowed =
                leftLength == 1 ||
                rangeSum(left, split) >= m;

            bool rightAllowed =
                rightLength == 1 ||
                rangeSum(split + 1, right) >= m;

            if (
                leftAllowed &&
                rightAllowed &&
                solve(left, split) &&
                solve(split + 1, right)
            ) {
                return memo[left][right] = 1;
            }
        }

        return memo[left][right] = 0;
    }

public:
    bool canSplitArray(vector<int>& nums, int inputM) {
        int n = static_cast<int>(nums.size());

        m = inputM;

        prefix.assign(n + 1, 0);

        for (int index = 0; index < n; index++) {
            prefix[index + 1] =
                prefix[index] +
                nums[index];
        }

        memo.assign(
            n,
            vector<int>(n, -1)
        );

        return solve(0, n - 1);
    }
};
