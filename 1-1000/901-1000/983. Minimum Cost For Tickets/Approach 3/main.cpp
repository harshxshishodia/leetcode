class Solution {
public:
    int mincostTickets(
        vector<int>& days,
        vector<int>& costs
    ) {
        int n = static_cast<int>(days.size());
        vector<int> dp(n + 1);

        for (int index = n - 1; index >= 0; index--) {
            int next7 =
                lower_bound(
                    days.begin(),
                    days.end(),
                    days[index] + 7
                ) -
                days.begin();

            int next30 =
                lower_bound(
                    days.begin(),
                    days.end(),
                    days[index] + 30
                ) -
                days.begin();

            dp[index] = min({
                costs[0] +
                dp[index + 1],
                costs[1] +
                dp[next7],
                costs[2] +
                dp[next30]
            });
        }

        return dp[0];
    }
};
