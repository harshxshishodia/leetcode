class Solution {
    bool hasUniqueDigits(int number) {
        if (number == 0) {
            return true;
        }

        array<bool, 10> seen = {};

        while (number > 0) {
            int digit = number % 10;

            if (seen[digit]) {
                return false;
            }

            seen[digit] = true;
            number /= 10;
        }

        return true;
    }

public:
    int countNumbersWithUniqueDigits(int n) {
        int limit = 1;

        for (int i = 0; i < n; i++) {
            limit *= 10;
        }

        int answer = 0;

        for (int number = 0; number < limit; number++) {
            if (hasUniqueDigits(number)) {
                answer++;
            }
        }

        return answer;
    }
};
