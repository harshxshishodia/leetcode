class Solution {
public:
    long long minCost(
        vector<int>& nums,
        vector<int>& costs
    ) {
        int n =
            static_cast<int>(nums.size());

        const long long INF =
            numeric_limits<long long>::max() / 4;

        vector<long long> dp(
            n,
            INF
        );

        vector<int> maximumStack;
        vector<int> minimumStack;

        dp[0] = 0;

        for (int index = 0; index < n; index++) {
            while (!maximumStack.empty() &&
                   nums[index] >=
                   nums[maximumStack.back()]) {
                dp[index] = min(
                    dp[index],
                    dp[maximumStack.back()] +
                    costs[index]
                );

                maximumStack.pop_back();
            }

            while (!minimumStack.empty() &&
                   nums[index] <
                   nums[minimumStack.back()]) {
                dp[index] = min(
                    dp[index],
                    dp[minimumStack.back()] +
                    costs[index]
                );

                minimumStack.pop_back();
            }

            maximumStack.push_back(index);
            minimumStack.push_back(index);
        }

        return dp[n - 1];
    }
};
