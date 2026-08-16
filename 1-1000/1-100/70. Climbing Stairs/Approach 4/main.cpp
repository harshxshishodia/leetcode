class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int previous2 = 1;
        int previous1 = 2;

        for (int i = 3; i <= n; i++) {
            int current = previous1 + previous2;
            previous2 = previous1;
            previous1 = current;
        }

        return previous1;
    }
};
