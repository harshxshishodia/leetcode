class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) {
            return true;
        }

        int total =
            maxChoosableInteger *
            (maxChoosableInteger + 1) / 2;

        if (total < desiredTotal) {
            return false;
        }

        int states = 1 << maxChoosableInteger;
        vector<int> sum(states);

        for (int mask = 1; mask < states; mask++) {
            int bit = mask & -mask;
            int index = __builtin_ctz(bit);
            sum[mask] = sum[mask ^ bit] + index + 1;
        }

        vector<bool> win(states);

        for (int mask = states - 1; mask >= 0; mask--) {
            int remaining = desiredTotal - sum[mask];

            for (int number = 1;
                 number <= maxChoosableInteger;
                 number++) {
                int bit = 1 << (number - 1);

                if ((mask & bit) != 0) {
                    continue;
                }

                if (number >= remaining ||
                    !win[mask | bit]) {
                    win[mask] = true;
                    break;
                }
            }
        }

        return win[0];
    }
};
