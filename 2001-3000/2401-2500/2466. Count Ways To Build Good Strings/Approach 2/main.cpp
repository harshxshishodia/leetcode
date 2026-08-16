class Solution {
    static constexpr int MOD =
        1000000007;

    vector<int> memo;

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

        if (memo[length] != -1) {
            return memo[length];
        }

        memo[length] =
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

        return memo[length];
    }

public:
    int countGoodStrings(
        int low,
        int high,
        int zero,
        int one
    ) {
        memo.assign(
            high + 1,
            -1
        );

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
