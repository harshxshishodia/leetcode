class Solution {
public:
    int rotatedDigits(int n) {
        string digits = to_string(n);

        array<array<long long, 2>, 2> dp = {};
        dp[1][0] = 1;

        for (char character : digits) {
            int limitDigit = character - '0';

            array<array<long long, 2>, 2> next = {};

            for (int tight = 0; tight <= 1; tight++) {
                for (int changed = 0; changed <= 1; changed++) {
                    long long ways = dp[tight][changed];

                    if (ways == 0) {
                        continue;
                    }

                    int limit =
                        tight
                            ? limitDigit
                            : 9;

                    for (int digit = 0; digit <= limit; digit++) {
                        if (digit == 3 ||
                            digit == 4 ||
                            digit == 7) {
                            continue;
                        }

                        int nextTight =
                            tight && digit == limitDigit;

                        int nextChanged =
                            changed ||
                            digit == 2 ||
                            digit == 5 ||
                            digit == 6 ||
                            digit == 9;

                        next[nextTight][nextChanged] += ways;
                    }
                }
            }

            dp = next;
        }

        return static_cast<int>(
            dp[0][1] +
            dp[1][1]
        );
    }
};
