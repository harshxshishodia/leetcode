class Solution {
    static constexpr long long MOD =
        1000000007;

    using Matrix =
        array<
            array<long long, 26>,
            26
        >;

    Matrix multiply(
        const Matrix& first,
        const Matrix& second
    ) {
        Matrix result = {};

        for (int row = 0;
             row < 26;
             row++) {
            for (int middle = 0;
                 middle < 26;
                 middle++) {
                if (first[row][middle] == 0) {
                    continue;
                }

                for (int col = 0;
                     col < 26;
                     col++) {
                    result[row][col] =
                        (
                            result[row][col] +
                            first[row][middle] *
                            second[middle][col]
                        ) %
                        MOD;
                }
            }
        }

        return result;
    }

    Matrix power(
        Matrix base,
        int exponent
    ) {
        Matrix result = {};

        for (int index = 0;
             index < 26;
             index++) {
            result[index][index] =
                1;
        }

        while (exponent > 0) {
            if (exponent & 1) {
                result =
                    multiply(
                        result,
                        base
                    );
            }

            base =
                multiply(
                    base,
                    base
                );

            exponent /=
                2;
        }

        return result;
    }

public:
    int lengthAfterTransformations(
        string s,
        int t
    ) {
        Matrix transition = {};

        for (int character = 0;
             character < 25;
             character++) {
            transition[
                character + 1
            ][character] =
                1;
        }

        transition[0][25] =
            1;

        transition[1][25] =
            1;

        Matrix transformed =
            power(
                transition,
                t
            );

        array<long long, 26> initial = {};

        for (char character :
             s) {
            initial[
                character -
                'a'
            ]++;
        }

        long long answer = 0;

        for (int row = 0;
             row < 26;
             row++) {
            long long count = 0;

            for (int col = 0;
                 col < 26;
                 col++) {
                count =
                    (
                        count +
                        transformed[row][col] *
                        initial[col]
                    ) %
                    MOD;
            }

            answer =
                (
                    answer +
                    count
                ) %
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
