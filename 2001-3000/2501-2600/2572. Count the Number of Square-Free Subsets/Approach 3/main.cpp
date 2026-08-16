class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        const int MOD =
            1000000007;

        array<int, 10> primes = {
            2,3,5,7,11,13,17,19,23,29
        };

        vector<int> dp(
            1 << 10
        );

        dp[0] = 1;

        for (int value : nums) {
            int original =
                value;

            int mask = 0;
            bool valid = true;

            for (int bit = 0; bit < 10; bit++) {
                int prime =
                    primes[bit];

                int count = 0;

                while (value % prime == 0) {
                    value /=
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

            vector<int> previous =
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
                        previous[used]
                    ) %
                    MOD;
            }
        }

        long long answer = 0;

        for (int ways : dp) {
            answer +=
                ways;
        }

        answer =
            (answer - 1) %
            MOD;

        if (answer < 0) {
            answer +=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
