class Solution {
    int generate(int remaining, int mask) {
        if (remaining == 0) {
            return 1;
        }

        int answer = 1;

        for (int digit = 0; digit <= 9; digit++) {
            if ((mask & (1 << digit)) != 0) {
                continue;
            }

            answer += generate(
                remaining - 1,
                mask | (1 << digit)
            );
        }

        return answer;
    }

public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }

        n = min(n, 10);
        int answer = 1;

        for (int first = 1; first <= 9; first++) {
            answer += generate(
                n - 1,
                1 << first
            );
        }

        return answer;
    }
};
