class Solution {
    static constexpr long long MOD =
        1000000007;

    long long power(
        long long base,
        long long exponent
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
    int numberOfSets(int n, int k) {
        int total =
            n + k - 1;

        int choose =
            2 * k;

        if (choose > total) {
            return 0;
        }

        vector<long long> factorial(
            total + 1,
            1
        );

        for (int i = 1; i <= total; i++) {
            factorial[i] =
                factorial[i - 1] *
                i %
                MOD;
        }

        long long denominator =
            factorial[choose] *
            factorial[total - choose] %
            MOD;

        long long answer =
            factorial[total] *
            power(
                denominator,
                MOD - 2
            ) %
            MOD;

        return static_cast<int>(answer);
    }
};
