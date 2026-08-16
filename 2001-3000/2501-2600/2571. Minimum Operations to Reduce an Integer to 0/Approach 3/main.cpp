class Solution {
public:
    int minOperations(int n) {
        vector<int> bits;

        int value =
            n;

        while (value > 0) {
            bits.push_back(
                value & 1
            );

            value >>= 1;
        }

        bits.push_back(0);
        bits.push_back(0);

        const int INF =
            1000000000;

        array<int, 2> dp = {
            0,
            INF
        };

        for (int bit : bits) {
            array<int, 2> next = {
                INF,
                INF
            };

            for (int carry = 0;
                 carry <= 1;
                 carry++) {
                if (dp[carry] == INF) {
                    continue;
                }

                int sum =
                    bit +
                    carry;

                for (int digit = -1;
                     digit <= 1;
                     digit++) {
                    int difference =
                        sum -
                        digit;

                    if (difference < 0 ||
                        difference % 2 != 0) {
                        continue;
                    }

                    int nextCarry =
                        difference /
                        2;

                    if (nextCarry > 1) {
                        continue;
                    }

                    next[nextCarry] = min(
                        next[nextCarry],
                        dp[carry] +
                        abs(digit)
                    );
                }
            }

            dp = next;
        }

        return dp[0];
    }
};
