class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) {
            return 1.0;
        }

        int maximumScore =
            k - 1 + maxPts;

        vector<double> dp(
            maximumScore + 1
        );

        for (int score = k;
             score <= maximumScore;
             score++) {
            dp[score] =
                score <= n
                    ? 1.0
                    : 0.0;
        }

        for (int score = k - 1;
             score >= 0;
             score--) {
            for (int points = 1;
                 points <= maxPts;
                 points++) {
                dp[score] +=
                    dp[score + points] /
                    maxPts;
            }
        }

        return dp[0];
    }
};
