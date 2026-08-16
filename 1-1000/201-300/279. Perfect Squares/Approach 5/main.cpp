class Solution {
    bool isPerfectSquare(int value) {
        int root = static_cast<int>(sqrt(value));
        return root * root == value;
    }

public:
    int numSquares(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }

        while (n % 4 == 0) {
            n /= 4;
        }

        if (n % 8 == 7) {
            return 4;
        }

        for (int first = 1; first * first <= n; first++) {
            int remaining = n - first * first;

            if (isPerfectSquare(remaining)) {
                return 2;
            }
        }

        return 3;
    }
};
