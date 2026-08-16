class Solution {
    int lower;
    int upper;
    int answer;

    void generate(long long number, int mask) {
        if (number > upper) {
            return;
        }

        if (number >= lower) {
            answer++;
        }

        for (int digit = 0; digit <= 9; digit++) {
            if ((mask & (1 << digit)) != 0) {
                continue;
            }

            long long next = number * 10 + digit;

            if (next > upper) {
                continue;
            }

            generate(next, mask | (1 << digit));
        }
    }

public:
    int numberCount(int a, int b) {
        lower = a;
        upper = b;
        answer = 0;

        for (int first = 1; first <= 9; first++) {
            if (first <= upper) {
                generate(first, 1 << first);
            }
        }

        return answer;
    }
};
