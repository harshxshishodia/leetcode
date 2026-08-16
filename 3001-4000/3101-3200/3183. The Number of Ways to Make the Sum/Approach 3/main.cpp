class Solution {
public:
    int numberOfWays(int n) {
        const int MOD =
            1000000007;

        vector<vector<int>> dp(
            3,
            vector<int>(
                n + 1
            )
        );

        dp[0][0] =
            1;

        for (int coin :
             {1, 2, 6}) {
            for (int usedFour = 0;
                 usedFour <= 2;
                 usedFour++) {
                for (int sum = coin;
                     sum <= n;
                     sum++) {
                    dp[usedFour][sum] =
                        (
                            dp[usedFour][sum] +
                            dp[usedFour][
                                sum -
                                coin
                            ]
                        ) %
                        MOD;
                }
            }
        }

        for (int usedFour = 1;
             usedFour <= 2;
             usedFour++) {
            for (int sum = 4;
                 sum <= n;
                 sum++) {
                dp[usedFour][sum] =
                    (
                        dp[usedFour][sum] +
                        dp[usedFour - 1][
                            sum -
                            4
                        ]
                    ) %
                    MOD;
            }
        }

        long long answer = 0;

        for (int usedFour = 0;
             usedFour <= 2;
             usedFour++) {
            answer +=
                dp[usedFour][n];
        }

        return static_cast<int>(
            answer %
            MOD
        );
    }
};
