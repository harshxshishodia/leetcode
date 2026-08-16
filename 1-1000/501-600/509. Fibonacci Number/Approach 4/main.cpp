class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        int previous2 = 0;
        int previous1 = 1;

        for (int i = 2; i <= n; i++) {
            int current = previous1 + previous2;
            previous2 = previous1;
            previous1 = current;
        }

        return previous1;
    }
};
