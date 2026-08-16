class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        vector<double> dp(
            n + 1
        );

        dp[1] = 1.0;

        for (int people = 2;
             people <= n;
             people++) {
            double answer =
                1.0 / people;

            for (int seat = 2;
                 seat < people;
                 seat++) {
                answer +=
                    dp[
                        people - seat + 1
                    ] /
                    people;
            }

            dp[people] = answer;
        }

        return dp[n];
    }
};
