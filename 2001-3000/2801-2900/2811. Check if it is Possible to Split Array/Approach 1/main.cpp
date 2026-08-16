class Solution {
    vector<long long> prefix;
    int m;

    long long rangeSum(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }

    bool solve(int left, int right) {
        if (right - left + 1 <= 2) {
            return true;
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
                return true;
            }
        }

        return false;
    }

public:
    bool canSplitArray(vector<int>& nums, int inputM) {
        m = inputM;

        prefix.assign(nums.size() + 1, 0);

        for (int index = 0; index < static_cast<int>(nums.size()); index++) {
            prefix[index + 1] =
                prefix[index] +
                nums[index];
        }

        return solve(
            0,
            static_cast<int>(nums.size()) - 1
        );
    }
};
