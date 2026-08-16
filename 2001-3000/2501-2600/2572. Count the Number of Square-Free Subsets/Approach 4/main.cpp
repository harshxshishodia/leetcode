class Solution {
    long long power(
        long long base,
        long long exponent,
        long long mod
    ) {
        long long answer = 1;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                answer =
                    answer *
                    base %
                    mod;
            }

            base =
                base *
                base %
                mod;

            exponent /= 2;
        }

        return answer;
    }

public:
    int squareFreeSubsets(vector<int>& nums) {
        const long long MOD =
            1000000007;

        array<int, 31> frequency = {};

        for (int value : nums) {
            frequency[value]++;
        }

        array<int, 10> primes = {
            2,3,5,7,11,13,17,19,23,29
        };

        vector<long long> dp(
            1 << 10
        );

        dp[0] = 1;

        for (int value = 2;
             value <= 30;
             value++) {
            if (frequency[value] == 0) {
                continue;
            }

            int current =
                value;

            int mask = 0;
            bool valid = true;

            for (int bit = 0; bit < 10; bit++) {
                int prime =
                    primes[bit];

                int count = 0;

                while (current % prime == 0) {
                    current /=
                        prime;

                    count++;
                }

                if (count >= 2) {
                    valid = false;
                    break;
                }

                if (count == 1) {
                    mask |=
                        1 << bit;
                }
            }

            if (!valid) {
                continue;
            }

            vector<long long> previous =
                dp;

            for (int used = 0;
                 used < (1 << 10);
                 used++) {
                if ((used & mask) != 0) {
                    continue;
                }

                dp[used | mask] =
                    (
                        dp[used | mask] +
                        previous[used] *
                        frequency[value]
                    ) %
                    MOD;
            }
        }

        long long total = 0;

        for (long long ways : dp) {
            total += ways;
            total %=
                MOD;
        }

        total =
            total *
            power(
                2,
                frequency[1],
                MOD
            ) %
            MOD;

        total =
            (total - 1 + MOD) %
            MOD;

        return static_cast<int>(
            total
        );
    }
};
