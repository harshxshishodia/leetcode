class Solution {
    static constexpr int MOD =
        1000000007;

    int ways(
        int length,
        int zero,
        int one
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
                    length - zero,
                    zero,
                    one
                ) +
                ways(
                    length - one,
                    zero,
                    one
                )
            ) %
            MOD;
    }

public:
    int countGoodStrings(
        int low,
        int high,
        int zero,
        int one
    ) {
        long long answer = 0;

        for (int length = low;
             length <= high;
             length++) {
            answer +=
                ways(
                    length,
                    zero,
                    one
                );

            answer %=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
