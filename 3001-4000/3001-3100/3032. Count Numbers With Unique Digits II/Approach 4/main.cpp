class Solution {
    long long permutations(int available, int positions) {
        long long result = 1;

        for (int i = 0; i < positions; i++) {
            result *= available - i;
        }

        return result;
    }

    long long countUpTo(int limit) {
        if (limit <= 0) {
            return 0;
        }

        string digits = to_string(limit);
        int length = static_cast<int>(digits.size());
        long long answer = 0;

        for (int size = 1; size < length; size++) {
            answer += 9 * permutations(9, size - 1);
        }

        int mask = 0;

        for (int position = 0; position < length; position++) {
            int current = digits[position] - '0';
            int firstDigit = position == 0 ? 1 : 0;

            for (int digit = firstDigit; digit < current; digit++) {
                if ((mask & (1 << digit)) != 0) {
                    continue;
                }

                int used = position + 1;
                int remaining = length - position - 1;
                answer += permutations(10 - used, remaining);
            }

            if ((mask & (1 << current)) != 0) {
                return answer;
            }

            mask |= 1 << current;
        }

        return answer + 1;
    }

public:
    int numberCount(int a, int b) {
        return static_cast<int>(countUpTo(b) - countUpTo(a - 1));
    }
};
