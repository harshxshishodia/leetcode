class Solution {
    static constexpr long long MOD =
        1000000007;

    long long power(
        long long base,
        int exponent
    ) {
        long long answer =
            1;

        while (exponent > 0) {
            if (exponent & 1) {
                answer =
                    answer *
                    base %
                    MOD;
            }

            base =
                base *
                base %
                MOD;

            exponent /=
                2;
        }

        return answer;
    }

public:
    int countOfArrays(
        int n,
        int m,
        int k
    ) {
        vector<long long> factorial(
            n + 1,
            1
        );

        vector<long long> inverseFactorial(
            n + 1,
            1
        );

        for (int index = 1;
             index <= n;
             index++) {
            factorial[index] =
                factorial[index - 1] *
                index %
                MOD;
        }

        inverseFactorial[n] =
            power(
                factorial[n],
                MOD -
                2
            );

        for (int index = n;
             index >= 1;
             index--) {
            inverseFactorial[index - 1] =
                inverseFactorial[index] *
                index %
                MOD;
        }

        auto combination =
            [&](int total, int choose) -> long long {
                if (
                    choose < 0 ||
                    choose > total ||
                    total < 0
                ) {
                    return 0;
                }

                return
                    factorial[total] *
                    inverseFactorial[choose] %
                    MOD *
                    inverseFactorial[total - choose] %
                    MOD;
            };

        long long evenChoices =
            m /
            2;

        long long oddChoices =
            m -
            evenChoices;

        long long answer = 0;

        if (k == 0) {
            answer =
                power(
                    oddChoices,
                    n
                );
        }

        for (int runs = 1;
             runs <= n;
             runs++) {
            int evenCount =
                k +
                runs;

            if (evenCount > n) {
                break;
            }

            int oddCount =
                n -
                evenCount;

            if (runs >
                oddCount +
                1) {
                continue;
            }

            long long patterns =
                combination(
                    evenCount -
                    1,
                    runs -
                    1
                ) *
                combination(
                    oddCount +
                    1,
                    runs
                ) %
                MOD;

            long long weighted =
                patterns *
                power(
                    evenChoices,
                    evenCount
                ) %
                MOD *
                power(
                    oddChoices,
                    oddCount
                ) %
                MOD;

            answer +=
                weighted;

            answer %=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
