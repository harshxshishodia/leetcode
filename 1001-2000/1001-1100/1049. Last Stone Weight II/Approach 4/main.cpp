class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(
            stones.begin(),
            stones.end(),
            0
        );

        int target =
            total / 2;

        vector<bool> dp(
            target + 1
        );

        dp[0] = true;

        for (int stone : stones) {
            for (int sum = target;
                 sum >= stone;
                 sum--) {
                dp[sum] =
                    dp[sum] ||
                    dp[sum - stone];
            }
        }

        for (int sum = target; sum >= 0; sum--) {
            if (dp[sum]) {
                return total - 2 * sum;
            }
        }

        return total;
    }
};
