class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = static_cast<int>(nums.size());

        vector<array<long long, 2>> dp(n + 1);

        for (int index = n - 1; index >= 1; index--) {
            int currentParity = nums[index] & 1;

            for (int parity = 0; parity <= 1; parity++) {
                long long skip = dp[index + 1][parity];

                long long take =
                    nums[index] -
                    (currentParity != parity ? x : 0) +
                    dp[index + 1][currentParity];

                dp[index][parity] = max(skip, take);
            }
        }

        return nums[0] + dp[1][nums[0] & 1];
    }
};
