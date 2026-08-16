class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(
            n + 1
        );

        for (int floors = 1;
             floors <= n;
             floors++) {
            dp[floors] =
                floors;

            for (int floor = 1;
                 floor <= floors;
                 floor++) {
                dp[floors] = min(
                    dp[floors],
                    1 +
                    max(
                        floor - 1,
                        dp[floors - floor]
                    )
                );
            }
        }

        return dp[n];
    }
};
