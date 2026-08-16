class Solution {
    static constexpr long long MOD = 1000000007;
    using Matrix = vector<vector<long long>>;

    Matrix multiply(
        const Matrix& first,
        const Matrix& second
    ) {
        int n = static_cast<int>(first.size());

        Matrix result(
            n,
            vector<long long>(n)
        );

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (first[i][k] == 0) {
                    continue;
                }

                for (int j = 0; j < n; j++) {
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
        int n = static_cast<int>(base.size());

        Matrix result(
            n,
            vector<long long>(n)
        );

        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }

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
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }

        Matrix transition(
            10,
            vector<long long>(10)
        );

        static const vector<vector<int>> next = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        for (int from = 0; from <= 9; from++) {
            for (int to : next[from]) {
                transition[to][from] = 1;
            }
        }

        Matrix result = power(
            transition,
            n - 1
        );

        long long answer = 0;

        for (int row = 0; row < 10; row++) {
            for (int col = 0; col < 10; col++) {
                answer += result[row][col];
                answer %= MOD;
            }
        }

        return static_cast<int>(answer);
    }
};
