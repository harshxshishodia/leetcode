class Solution {
    bool canJump(
        const vector<int>& nums,
        int first,
        int second
    ) {
        if (nums[first] <= nums[second]) {
            for (int index = first + 1;
                 index < second;
                 index++) {
                if (nums[index] >=
                    nums[first]) {
                    return false;
                }
            }

            return true;
        }

        for (int index = first + 1;
             index < second;
             index++) {
            if (nums[index] <
                nums[first]) {
                return false;
            }
        }

        return true;
    }

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

        dp[0] = 0;

        for (int second = 1; second < n; second++) {
            for (int first = 0; first < second; first++) {
                if (canJump(
                        nums,
                        first,
                        second)) {
                    dp[second] = min(
                        dp[second],
                        dp[first] +
                        costs[second]
                    );
                }
            }
        }

        return dp[n - 1];
    }
};
