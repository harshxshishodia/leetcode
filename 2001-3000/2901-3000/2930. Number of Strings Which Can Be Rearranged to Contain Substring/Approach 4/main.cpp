class Solution {
    static constexpr long long MOD =
        1000000007;

    long long power(
        long long base,
        int exponent
    ) {
        long long answer = 1;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                answer =
                    answer *
                    base %
                    MOD;
            }

            base =
                base *
                base %
                MOD;

            exponent /= 2;
        }

        return answer;
    }

public:
    int stringCount(int n) {
        long long total =
            power(
                26,
                n
            );

        long long noL =
            power(
                25,
                n
            );

        long long noT =
            noL;

        long long fewE =
            (
                power(
                    25,
                    n
                ) +
                (
                    n == 0
                        ? 0
                        : 1LL *
                          n *
                          power(
                              25,
                              n - 1
                          ) %
                          MOD
                )
            ) %
            MOD;

        long long noLNoT =
            power(
                24,
                n
            );

        long long noLFewE =
            (
                power(
                    24,
                    n
                ) +
                (
                    n == 0
                        ? 0
                        : 1LL *
                          n *
                          power(
                              24,
                              n - 1
                          ) %
                          MOD
                )
            ) %
            MOD;

        long long noTFewE =
            noLFewE;

        long long allThree =
            (
                power(
                    23,
                    n
                ) +
                (
                    n == 0
                        ? 0
                        : 1LL *
                          n *
                          power(
                              23,
                              n - 1
                          ) %
                          MOD
                )
            ) %
            MOD;

        long long answer =
            total;

        answer =
            (
                answer -
                noL -
                noT -
                fewE
            ) %
            MOD;

        answer =
            (
                answer +
                noLNoT +
                noLFewE +
                noTFewE
            ) %
            MOD;

        answer =
            (
                answer -
                allThree
            ) %
            MOD;

        if (answer < 0) {
            answer +=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
