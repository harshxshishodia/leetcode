class Solution {
public:
    int maxScore(
        int n,
        int k,
        vector<vector<int>>& stayScore,
        vector<vector<int>>& travelScore
    ) {
        vector<vector<int>> dp(
            k + 1,
            vector<int>(n)
        );

        for (int day = k - 1;
             day >= 0;
             day--) {
            for (int city = 0;
                 city < n;
                 city++) {
                dp[day][city] =
                    stayScore[day][city] +
                    dp[day + 1][city];

                for (int destination = 0;
                     destination < n;
                     destination++) {
                    if (destination == city) {
                        continue;
                    }

                    dp[day][city] = max(
                        dp[day][city],
                        travelScore[city][destination] +
                        dp[day + 1][destination]
                    );
                }
            }
        }

        return *max_element(
            dp[0].begin(),
            dp[0].end()
        );
    }
};
