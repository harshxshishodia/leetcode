class Solution {
    static constexpr long long MOD =
        1000000007;

    using Matrix =
        vector<vector<long long>>;

    void buildRows(
        int width,
        const vector<int>& bricks,
        int used,
        int mask,
        vector<int>& rows
    ) {
        if (used == width) {
            rows.push_back(mask);
            return;
        }

        for (int brick : bricks) {
            int next =
                used + brick;

            if (next > width) {
                continue;
            }

            int nextMask =
                mask;

            if (next < width) {
                nextMask |=
                    1 << next;
            }

            buildRows(
                width,
                bricks,
                next,
                nextMask,
                rows
            );
        }
    }

    Matrix multiply(
        const Matrix& first,
        const Matrix& second
    ) {
        int n =
            static_cast<int>(first.size());

        Matrix result(
            n,
            vector<long long>(n)
        );

        for (int row = 0; row < n; row++) {
            for (int middle = 0; middle < n; middle++) {
                if (first[row][middle] == 0) {
                    continue;
                }

                for (int col = 0; col < n; col++) {
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
        int n =
            static_cast<int>(base.size());

        Matrix result(
            n,
            vector<long long>(n)
        );

        for (int index = 0; index < n; index++) {
            result[index][index] = 1;
        }

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = multiply(
                    result,
                    base
                );
            }

            base = multiply(
                base,
                base
            );

            exponent /= 2;
        }

        return result;
    }

public:
    int buildWall(
        int height,
        int width,
        vector<int>& bricks
    ) {
        vector<int> rows;

        buildRows(
            width,
            bricks,
            0,
            0,
            rows
        );

        int count =
            static_cast<int>(rows.size());

        if (count == 0) {
            return 0;
        }

        if (height == 1) {
            return count;
        }

        Matrix transition(
            count,
            vector<long long>(count)
        );

        for (int first = 0; first < count; first++) {
            for (int second = 0; second < count; second++) {
                if ((rows[first] &
                     rows[second]) == 0) {
                    transition[first][second] = 1;
                }
            }
        }

        Matrix result =
            power(
                transition,
                height - 1
            );

        long long answer = 0;

        for (int first = 0; first < count; first++) {
            for (int second = 0; second < count; second++) {
                answer +=
                    result[first][second];

                answer %=
                    MOD;
            }
        }

        return static_cast<int>(answer);
    }
};
