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
    int climbStairs(int n) {
        Matrix fibonacci = {{{1, 1}, {1, 0}}};
        Matrix result = power(fibonacci, n);
        return static_cast<int>(result[0][0]);
    }
};
