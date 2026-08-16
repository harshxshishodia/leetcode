class Solution {
public:
    int maxResult(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(nums.size());

        vector<int> dp(n);
        dp[n - 1] = nums[n - 1];

        for (int index = n - 2;
             index >= 0;
             index--) {
            int best =
                numeric_limits<int>::min();

            for (int next = index + 1;
                 next < n &&
                 next <= index + k;
                 next++) {
                best = max(
                    best,
                    dp[next]
                );
            }

            dp[index] =
                nums[index] +
                best;
        }

        return dp[0];
    }
};
