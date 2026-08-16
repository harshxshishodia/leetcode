class Solution {
    array<array<int, 10>, 10> skip;

    int search(
        int current,
        int remaining,
        int mask
    ) {
        if (remaining == 0) {
            return 1;
        }

        int answer = 0;

        for (int next = 1; next <= 9; next++) {
            int bit = 1 << (next - 1);

            if ((mask & bit) != 0) {
                continue;
            }

            int middle = skip[current][next];

            if (middle != 0 &&
                (mask & (1 << (middle - 1))) == 0) {
                continue;
            }

            answer += search(
                next,
                remaining - 1,
                mask | bit
            );
        }

        return answer;
    }

    void buildSkip() {
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = 5;
        skip[3][7] = skip[7][3] = 5;
        skip[4][6] = skip[6][4] = 5;
        skip[2][8] = skip[8][2] = 5;
    }

public:
    int numberOfPatterns(int m, int n) {
        buildSkip();
        int answer = 0;

        for (int length = m; length <= n; length++) {
            int corner = search(1, length - 1, 1 << 0);
            int edge = search(2, length - 1, 1 << 1);
            int center = search(5, length - 1, 1 << 4);

            answer += corner * 4;
            answer += edge * 4;
            answer += center;
        }

        return answer;
    }
};
