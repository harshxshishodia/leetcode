class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return 0;
        }

        int rows = static_cast<int>(mat.size());
        int cols = static_cast<int>(mat[0].size());

        vector<array<int, 4>> previous(cols);
        vector<array<int, 4>> current(cols);
        int answer = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                current[col] = {0, 0, 0, 0};

                if (mat[row][col] == 0) {
                    continue;
                }

                current[col][0] =
                    1 + (col > 0 ? current[col - 1][0] : 0);

                current[col][1] =
                    1 + previous[col][1];

                current[col][2] =
                    1 + (col > 0 ? previous[col - 1][2] : 0);

                current[col][3] =
                    1 + (
                        col + 1 < cols
                            ? previous[col + 1][3]
                            : 0
                    );

                answer = max({
                    answer,
                    current[col][0],
                    current[col][1],
                    current[col][2],
                    current[col][3]
                });
            }

            previous = current;
        }

        return answer;
    }
};
