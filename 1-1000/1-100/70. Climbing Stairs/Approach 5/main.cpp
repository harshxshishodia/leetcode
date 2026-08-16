class Solution {
public:
    int climbStairs(int n) {
        long long ways = 1;
        long long term = 1;

        for (int twos = 0; twos < n / 2; twos++) {
            term = term * (n - 2 * twos) * (n - 2 * twos - 1);
            term /= (twos + 1) * (n - twos);
            ways += term;
        }

        return static_cast<int>(ways);
    }
};
