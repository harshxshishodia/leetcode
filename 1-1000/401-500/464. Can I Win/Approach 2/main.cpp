class Solution {
    int memo[1 << 20];

    bool solve(
        int maximum,
        int remaining,
        int usedMask
    ) {
        if (memo[usedMask] != 0) {
            return memo[usedMask] == 1;
        }

        for (int number = 1; number <= maximum; number++) {
            int bit = 1 << (number - 1);

            if ((usedMask & bit) != 0) {
                continue;
            }

            if (number >= remaining ||
                !solve(
                    maximum,
                    remaining - number,
                    usedMask | bit)) {
                memo[usedMask] = 1;
                return true;
            }
        }

        memo[usedMask] = -1;
        return false;
    }

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

        memset(memo, 0, sizeof(memo));

        return solve(
            maxChoosableInteger,
            desiredTotal,
            0
        );
    }
};
