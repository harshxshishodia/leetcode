class Solution {
public:
    double soupServings(int n) {
        int units =
            (n + 24) /
            25;

        vector<vector<double>> dp(
            units + 1,
            vector<double>(
                units + 1
            )
        );

        dp[0][0] = 0.5;

        for (int b = 1; b <= units; b++) {
            dp[0][b] = 1.0;
        }

        for (int a = 1; a <= units; a++) {
            dp[a][0] = 0.0;
        }

        for (int a = 1; a <= units; a++) {
            for (int b = 1; b <= units; b++) {
                dp[a][b] =
                    0.25 * (
                        dp[max(0, a - 4)][b] +
                        dp[max(0, a - 3)][max(0, b - 1)] +
                        dp[max(0, a - 2)][max(0, b - 2)] +
                        dp[max(0, a - 1)][max(0, b - 3)]
                    );
            }
        }

        return dp[units][units];
    }
};
