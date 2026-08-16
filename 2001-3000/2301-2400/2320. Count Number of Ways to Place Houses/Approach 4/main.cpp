class Solution {
public:
    int countHousePlacements(int n) {
        const long long MOD =
            1000000007;

        long long empty = 1;
        long long house = 0;

        for (int plot = 0;
             plot < n;
             plot++) {
            long long nextEmpty =
                (
                    empty +
                    house
                ) %
                MOD;

            long long nextHouse =
                empty;

            empty =
                nextEmpty;

            house =
                nextHouse;
        }

        long long oneSide =
            (
                empty +
                house
            ) %
            MOD;

        return static_cast<int>(
            oneSide *
            oneSide %
            MOD
        );
    }
};
