class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = static_cast<int>(nums.size());

        if (n <= 2) {
            return true;
        }

        vector<long long> prefix(n + 1);

        for (int index = 0; index < n; index++) {
            prefix[index + 1] =
                prefix[index] +
                nums[index];
        }

        vector<vector<bool>> dp(
            n,
            vector<bool>(n)
        );

        for (int length = 1; length <= n; length++) {
            for (int left = 0; left + length <= n; left++) {
                int right =
                    left +
                    length -
                    1;

                if (length <= 2) {
                    dp[left][right] = true;
                    continue;
                }

                for (int split = left; split < right; split++) {
                    int leftLength =
                        split -
                        left +
                        1;

                    int rightLength =
                        right -
                        split;

                    long long leftSum =
                        prefix[split + 1] -
                        prefix[left];

                    long long rightSum =
                        prefix[right + 1] -
                        prefix[split + 1];

                    if (
                        (
                            leftLength == 1 ||
                            leftSum >= m
                        ) &&
                        (
                            rightLength == 1 ||
                            rightSum >= m
                        ) &&
                        dp[left][split] &&
                        dp[split + 1][right]
                    ) {
                        dp[left][right] = true;
                        break;
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
