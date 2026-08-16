class Solution {
    bool hasUniqueDigits(int number) {
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
    int numberCount(int a, int b) {
        int answer = 0;

        for (int number = a; number <= b; number++) {
            if (hasUniqueDigits(number)) {
                answer++;
            }
        }

        return answer;
    }
};
