class Solution {
    static constexpr int MOD =
        1000000007;

    vector<int> memo;

    int ways(
        int length,
        int oneGroup,
        int zeroGroup
    ) {
        if (length == 0) {
            return 1;
        }

        if (length < 0) {
            return 0;
        }

        if (memo[length] != -1) {
            return memo[length];
        }

        memo[length] =
            (
                ways(
                    length - oneGroup,
                    oneGroup,
                    zeroGroup
                ) +
                ways(
                    length - zeroGroup,
                    oneGroup,
                    zeroGroup
                )
            ) %
            MOD;

        return memo[length];
    }

public:
    int goodBinaryStrings(
        int minLength,
        int maxLength,
        int oneGroup,
        int zeroGroup
    ) {
        memo.assign(
            maxLength + 1,
            -1
        );

        long long answer = 0;

        for (int length = minLength;
             length <= maxLength;
             length++) {
            answer +=
                ways(
                    length,
                    oneGroup,
                    zeroGroup
                );

            answer %=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
