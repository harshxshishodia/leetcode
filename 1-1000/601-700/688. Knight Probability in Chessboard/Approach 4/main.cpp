class Solution {
public:
    double knightProbability(
        int n,
        int k,
        int row,
        int column
    ) {
        static const array<pair<int, int>, 8> directions = {{
            {-2, -1},
            {-2, 1},
            {-1, -2},
            {-1, 2},
            {1, -2},
            {1, 2},
            {2, -1},
            {2, 1}
        }};

        vector<vector<double>> current(
            n,
            vector<double>(n)
        );

        current[row][column] = 1.0;

        for (int move = 0; move < k; move++) {
            vector<vector<double>> next(
                n,
                vector<double>(n)
            );

            for (int currentRow = 0; currentRow < n; currentRow++) {
                for (int currentCol = 0; currentCol < n; currentCol++) {
                    if (current[currentRow][currentCol] == 0.0) {
                        continue;
                    }

                    for (auto [rowChange, colChange] : directions) {
                        int nextRow =
                            currentRow + rowChange;

                        int nextCol =
                            currentCol + colChange;

                        if (nextRow < 0 ||
                            nextRow >= n ||
                            nextCol < 0 ||
                            nextCol >= n) {
                            continue;
                        }

                        next[nextRow][nextCol] +=
                            current[currentRow][currentCol] /
                            8.0;
                    }
                }
            }

            current = next;
        }

        double answer = 0.0;

        for (const vector<double>& currentRow : current) {
            for (double probability : currentRow) {
                answer += probability;
            }
        }

        return answer;
    }
};
