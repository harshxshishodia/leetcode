class Solution {
    using Matrix = array<array<long long, 2>, 2>;

    Matrix multiply(const Matrix& first, const Matrix& second) {
        Matrix result = {{{0, 0}, {0, 0}}};

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    result[i][j] += first[i][k] * second[k][j];
                }
            }
        }

        return result;
    }

    Matrix power(Matrix base, int exponent) {
        Matrix result = {{{1, 0}, {0, 1}}};

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = multiply(result, base);
            }

            base = multiply(base, base);
            exponent /= 2;
        }

        return result;
    }

public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            return 0;
        }

        if (n == 1) {
            return k;
        }

        if (n == 2) {
            return k * k;
        }

        long long factor = k - 1;
        Matrix transition = {{
            {factor, factor},
            {1, 0}
        }};

        Matrix result = power(transition, n - 2);
        long long answer =
            result[0][0] * 1LL * k * k +
            result[0][1] * k;

        return static_cast<int>(answer);
    }
};
