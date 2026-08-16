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
    int numberOfWays(
        int startPos,
        int endPos,
        int k
    ) {
        int distance =
            abs(
                endPos -
                startPos
            );

        if (distance > k ||
            (k - distance) % 2 != 0) {
            return 0;
        }

        int right =
            (
                k +
                endPos -
                startPos
            ) /
            2;

        if (right < 0 ||
            right > k) {
            return 0;
        }

        vector<long long> factorial(
            k + 1,
            1
        );

        for (int value = 1;
             value <= k;
             value++) {
            factorial[value] =
                factorial[value - 1] *
                value %
                MOD;
        }

        long long denominator =
            factorial[right] *
            factorial[k - right] %
            MOD;

        return static_cast<int>(
            factorial[k] *
            power(
                denominator,
                MOD - 2
            ) %
            MOD
        );
    }
};
