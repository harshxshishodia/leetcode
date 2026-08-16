class Solution {
    static constexpr int MOD =
        1000000007;

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

        return
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
    }

public:
    int goodBinaryStrings(
        int minLength,
        int maxLength,
        int oneGroup,
        int zeroGroup
    ) {
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
