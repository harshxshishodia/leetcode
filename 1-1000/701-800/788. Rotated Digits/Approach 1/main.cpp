class Solution {
    bool good(int number) {
        bool changed = false;

        while (number > 0) {
            int digit = number % 10;

            if (digit == 3 ||
                digit == 4 ||
                digit == 7) {
                return false;
            }

            if (digit == 2 ||
                digit == 5 ||
                digit == 6 ||
                digit == 9) {
                changed = true;
            }

            number /= 10;
        }

        return changed;
    }

public:
    int rotatedDigits(int n) {
        int answer = 0;

        for (int number = 1; number <= n; number++) {
            if (good(number)) {
                answer++;
            }
        }

        return answer;
    }
};
