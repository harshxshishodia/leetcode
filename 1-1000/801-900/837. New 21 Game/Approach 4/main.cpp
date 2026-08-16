class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 ||
            n >= k - 1 + maxPts) {
            return 1.0;
        }

        vector<double> dp(
            n + 1
        );

        dp[0] = 1.0;

        double windowSum = 1.0;
        double answer = 0.0;

        for (int score = 1; score <= n; score++) {
            dp[score] =
                windowSum /
                maxPts;

            if (score < k) {
                windowSum +=
                    dp[score];
            } else {
                answer +=
                    dp[score];
            }

            if (score - maxPts >= 0 &&
                score - maxPts < k) {
                windowSum -=
                    dp[score - maxPts];
            }
        }

        return answer;
    }
};
