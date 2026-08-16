class Solution {
    array<array<int, 10>, 10> skip;

    int search(
        int current,
        int remaining,
        vector<bool>& used
    ) {
        if (remaining == 0) {
            return 1;
        }

        int answer = 0;

        for (int next = 1; next <= 9; next++) {
            int middle = skip[current][next];

            if (used[next] ||
                (middle != 0 && !used[middle])) {
                continue;
            }

            used[next] = true;
            answer += search(
                next,
                remaining - 1,
                used
            );
            used[next] = false;
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
        vector<bool> used(10);
        int answer = 0;

        for (int length = m; length <= n; length++) {
            for (int start = 1; start <= 9; start++) {
                used[start] = true;
                answer += search(
                    start,
                    length - 1,
                    used
                );
                used[start] = false;
            }
        }

        return answer;
    }
};
