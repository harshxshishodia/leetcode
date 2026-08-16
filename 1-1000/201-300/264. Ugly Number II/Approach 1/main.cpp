class Solution {
    bool isUgly(int number) {
        if (number <= 0) {
            return false;
        }

        for (int factor : {2, 3, 5}) {
            while (number % factor == 0) {
                number /= factor;
            }
        }

        return number == 1;
    }

public:
    int nthUglyNumber(int n) {
        int count = 0;
        int number = 0;

        while (count < n) {
            number++;

            if (isUgly(number)) {
                count++;
            }
        }

        return number;
    }
};
