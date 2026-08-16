class Solution {
    using Matrix = array<array<long long, 3>, 3>;

    Matrix multiply(const Matrix& first, const Matrix& second) {
        Matrix result = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    result[i][j] += first[i][k] * second[k][j];
                }
            }
        }

        return result;
    }

    Matrix power(Matrix base, int exponent) {
        Matrix result = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};

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
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }

        if (n <= 2) {
            return 1;
        }

        Matrix transition = {{{1, 1, 1}, {1, 0, 0}, {0, 1, 0}}};
        Matrix result = power(transition, n - 2);

        return static_cast<int>(result[0][0] + result[0][1]);
    }
};
