class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const int MOD =
            1000000007;

        int n =
            static_cast<int>(nums.size());

        vector<int> prefix(
            n + 1
        );

        for (int index = 0;
             index < n;
             index++) {
            prefix[index + 1] =
                prefix[index] +
                nums[index];
        }

        vector<long long> dp(
            n + 1
        );

        dp[0] = 1;

        for (int end = 1;
             end <= n;
             end++) {
            for (int start = 0;
                 start < end;
                 start++) {
                if (prefix[end] -
                    prefix[start] ==
                    1) {
                    dp[end] +=
                        dp[start];

                    dp[end] %=
                        MOD;
                }
            }
        }

        return static_cast<int>(
            dp[n]
        );
    }
};
