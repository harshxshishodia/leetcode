class Solution {
    static constexpr long long MOD = 1000000007;

    using Matrix =
        array<array<long long, 3>, 3>;

    Matrix multiply(
        const Matrix& first,
        const Matrix& second
    ) {
        Matrix result = {{
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        }};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    result[i][j] =
                        (
                            result[i][j] +
                            first[i][k] *
                            second[k][j]
                        ) %
                        MOD;
                }
            }
        }

        return result;
    }

    Matrix power(
        Matrix base,
        int exponent
    ) {
        Matrix result = {{
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        }};

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = multiply(
                    result,
                    base
                );
            }

            base = multiply(
                base,
                base
            );

            exponent /= 2;
        }

        return result;
    }

public:
    int numTilings(int n) {
        if (n == 0) {
            return 1;
        }

        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        Matrix transition = {{
            {2, 0, 1},
            {1, 0, 0},
            {0, 1, 0}
        }};

        Matrix result = power(
            transition,
            n - 2
        );

        long long answer =
            (
                result[0][0] * 2 +
                result[0][1] * 1 +
                result[0][2] * 1
            ) %
            MOD;

        return static_cast<int>(
            answer
        );
    }
};
