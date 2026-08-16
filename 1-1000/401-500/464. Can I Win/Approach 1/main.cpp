class Solution {
    bool solve(
        int maximum,
        int remaining,
        int usedMask
    ) {
        for (int number = 1; number <= maximum; number++) {
            int bit = 1 << (number - 1);

            if ((usedMask & bit) != 0) {
                continue;
            }

            if (number >= remaining) {
                return true;
            }

            if (!solve(
                    maximum,
                    remaining - number,
                    usedMask | bit)) {
                return true;
            }
        }

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

        return solve(
            maxChoosableInteger,
            desiredTotal,
            0
        );
    }
};
