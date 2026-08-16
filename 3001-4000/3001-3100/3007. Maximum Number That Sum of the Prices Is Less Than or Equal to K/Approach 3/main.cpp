class Solution {
    struct Result {
        long long count;
        long long price;
    };

    int x;
    vector<int> bits;
    array<Result, 61> memo;
    array<bool, 61> visited;

    Result solve(
        int bit,
        bool tight
    ) {
        if (bit < 0) {
            return {
                1,
                0
            };
        }

        if (!tight &&
            visited[bit]) {
            return memo[bit];
        }

        int maximum =
            tight
                ? bits[bit]
                : 1;

        __int128 count = 0;
        __int128 price = 0;

        for (int digit = 0;
             digit <= maximum;
             digit++) {
            Result next =
                solve(
                    bit - 1,
                    tight &&
                    digit ==
                    maximum
                );

            count +=
                next.count;

            price +=
                next.price;

            if (
                digit == 1 &&
                (bit + 1) %
                    x ==
                    0
            ) {
                price +=
                    next.count;
            }
        }

        Result answer = {
            static_cast<long long>(
                count
            ),
            price >
                    numeric_limits<long long>::max()
                ? numeric_limits<long long>::max()
                : static_cast<long long>(
                    price
                )
        };

        if (!tight) {
            visited[bit] =
                true;

            memo[bit] =
                answer;
        }

        return answer;
    }

    long long totalPrice(
        long long limit
    ) {
        bits.assign(
            61,
            0
        );

        for (int bit = 0;
             bit <= 60;
             bit++) {
            bits[bit] =
                (
                    limit >>
                    bit
                ) &
                1LL;
        }

        visited.fill(
            false
        );

        return solve(
            60,
            true
        ).price;
    }

public:
    long long findMaximumNumber(
        long long k,
        int inputX
    ) {
        x =
            inputX;

        long long left = 0;
        long long right =
            1000000000000000LL;

        while (left < right) {
            long long middle =
                left +
                (right - left + 1) /
                2;

            if (totalPrice(
                    middle) <=
                k) {
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
