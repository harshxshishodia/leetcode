class Solution {
    int price(
        long long value,
        int x
    ) {
        int answer = 0;
        int position = 1;

        while (value > 0) {
            if (
                position %
                    x ==
                    0 &&
                (value & 1LL)
            ) {
                answer++;
            }

            value >>=
                1;

            position++;
        }

        return answer;
    }

public:
    long long findMaximumNumber(
        long long k,
        int x
    ) {
        long long total = 0;
        long long value = 0;

        while (true) {
            long long next =
                value +
                1;

            int nextPrice =
                price(
                    next,
                    x
                );

            if (total +
                nextPrice >
                k) {
                return value;
            }

            total +=
                nextPrice;

            value =
                next;
        }
    }
};
