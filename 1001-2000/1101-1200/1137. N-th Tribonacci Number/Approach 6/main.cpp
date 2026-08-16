class Solution {
    array<long long, 3> combine(
        const array<long long, 3>& first,
        const array<long long, 3>& second
    ) {
        array<long long, 5> product = {0, 0, 0, 0, 0};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                product[i + j] += first[i] * second[j];
            }
        }

        for (int degree = 4; degree >= 3; degree--) {
            long long value = product[degree];
            product[degree - 1] += value;
            product[degree - 2] += value;
            product[degree - 3] += value;
        }

        return {product[0], product[1], product[2]};
    }

public:
    int tribonacci(int n) {
        array<long long, 3> result = {1, 0, 0};
        array<long long, 3> base = {0, 1, 0};

        while (n > 0) {
            if (n % 2 == 1) {
                result = combine(result, base);
            }

            base = combine(base, base);
            n /= 2;
        }

        return static_cast<int>(result[1] + result[2]);
    }
};
