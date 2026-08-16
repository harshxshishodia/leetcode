class Solution {
public:
    int mincostTickets(
        vector<int>& days,
        vector<int>& costs
    ) {
        vector<bool> travel(366);

        for (int day : days) {
            travel[day] = true;
        }

        vector<int> dp(366);

        for (int day = 1; day <= 365; day++) {
            if (!travel[day]) {
                dp[day] =
                    dp[day - 1];

                continue;
            }

            dp[day] = min({
                dp[day - 1] +
                costs[0],
                dp[max(0, day - 7)] +
                costs[1],
                dp[max(0, day - 30)] +
                costs[2]
            });
        }

        return dp[365];
    }
};
