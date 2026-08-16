class Solution {
public:
    int findDerangement(int n) {
        const int MOD = 1000000007;

        if (n == 0) {
            return 1;
        }

        if (n == 1) {
            return 0;
        }

        long long previous2 = 1;
        long long previous1 = 0;

        for (int value = 2; value <= n; value++) {
            long long current =
                1LL *
                (value - 1) *
                (previous1 + previous2) %
                MOD;

            previous2 = previous1;
            previous1 = current;
        }

        return static_cast<int>(previous1);
    }
};
