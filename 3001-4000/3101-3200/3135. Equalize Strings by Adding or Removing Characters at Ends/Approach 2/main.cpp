class Solution {
public:
    int minOperations(
        string initial,
        string target
    ) {
        int firstLength =
            static_cast<int>(
                initial.size()
            );

        int secondLength =
            static_cast<int>(
                target.size()
            );

        vector<vector<int>> dp(
            firstLength + 1,
            vector<int>(
                secondLength + 1
            )
        );

        int best = 0;

        for (int first = 1;
             first <= firstLength;
             first++) {
            for (int second = 1;
                 second <= secondLength;
                 second++) {
                if (
                    initial[first - 1] ==
                    target[second - 1]
                ) {
                    dp[first][second] =
                        dp[first - 1][second - 1] +
                        1;

                    best = max(
                        best,
                        dp[first][second]
                    );
                }
            }
        }

        return
            firstLength +
            secondLength -
            2 *
            best;
    }
};
