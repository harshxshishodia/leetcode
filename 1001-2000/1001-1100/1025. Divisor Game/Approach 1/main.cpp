class Solution {
    bool canWin(int n) {
        if (n == 1) {
            return false;
        }

        for (int divisor = 1; divisor < n; divisor++) {
            if (n % divisor == 0 && !canWin(n - divisor)) {
                return true;
            }
        }

        return false;
    }

public:
    bool divisorGame(int n) {
        return canWin(n);
    }
};
