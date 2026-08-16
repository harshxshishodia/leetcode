class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        vector<int> dp(
            n
        );

        for (int index = n - 2;
             index >= 0;
             index--) {
            for (int next = index + 1;
                 next < n;
                 next++) {
                dp[index] = max(
                    dp[index],
                    (
                        next -
                        index
                    ) *
                    nums[next] +
                    dp[next]
                );
            }
        }

        return dp[0];
    }
};
