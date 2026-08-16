class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            return 0;
        }

        if (n == 1) {
            return k;
        }

        long long previous2 = k;
        long long previous1 = 1LL * k * k;

        for (int posts = 3; posts <= n; posts++) {
            long long current = 1LL * (k - 1) *
                                (previous1 + previous2);

            previous2 = previous1;
            previous1 = current;
        }

        return static_cast<int>(previous1);
    }
};
