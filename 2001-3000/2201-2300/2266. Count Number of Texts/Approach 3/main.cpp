class Solution {
public:
    int countTexts(string pressedKeys) {
        const int MOD =
            1000000007;

        int n =
            static_cast<int>(pressedKeys.size());

        vector<long long> dp(
            n + 1
        );

        dp[n] = 1;

        for (int index = n - 1;
             index >= 0;
             index--) {
            int maximum =
                (
                    pressedKeys[index] == '7' ||
                    pressedKeys[index] == '9'
                )
                    ? 4
                    : 3;

            for (int length = 1;
                 length <= maximum &&
                 index + length <= n;
                 length++) {
                if (pressedKeys[index + length - 1] !=
                    pressedKeys[index]) {
                    break;
                }

                dp[index] +=
                    dp[index + length];

                dp[index] %=
                    MOD;
            }
        }

        return static_cast<int>(
            dp[0]
        );
    }
};
