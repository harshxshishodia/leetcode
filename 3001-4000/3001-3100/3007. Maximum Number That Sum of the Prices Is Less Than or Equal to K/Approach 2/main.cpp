class Solution {
    long long totalPrice(
        long long limit,
        int x
    ) {
        __int128 answer = 0;

        for (int position = x;
             position <= 60;
             position += x) {
            int bit =
                position -
                1;

            long long half =
                1LL <<
                bit;

            long long cycle =
                half <<
                1;

            long long count =
                limit +
                1;

            long long complete =
                count /
                cycle;

            long long remainder =
                count %
                cycle;

            __int128 ones =
                static_cast<__int128>(
                    complete
                ) *
                half +
                max(
                    0LL,
                    remainder -
                    half
                );

            answer +=
                ones;
        }

        if (answer >
            numeric_limits<long long>::max()) {
            return
                numeric_limits<long long>::max();
        }

        return static_cast<long long>(
            answer
        );
    }

public:
    long long findMaximumNumber(
        long long k,
        int x
    ) {
        long long left = 0;
        long long right =
            1000000000000000LL;

        while (left < right) {
            long long middle =
                left +
                (right - left + 1) /
                2;

            if (totalPrice(
                    middle,
                    x) <= k) {
                left =
                    middle;
            } else {
                right =
                    middle -
                    1;
            }
        }

        return left;
    }
};
