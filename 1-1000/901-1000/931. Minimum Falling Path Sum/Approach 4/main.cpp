class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = static_cast<int>(matrix.size());
        vector<int> previous = matrix[0];

        for (int row = 1; row < n; row++) {
            vector<int> current(n);

            for (int col = 0; col < n; col++) {
                int best =
                    previous[col];

                if (col > 0) {
                    best = min(
                        best,
                        previous[col - 1]
                    );
                }

                if (col + 1 < n) {
                    best = min(
                        best,
                        previous[col + 1]
                    );
                }

                current[col] =
                    matrix[row][col] +
                    best;
            }

            previous = current;
        }

        return *min_element(
            previous.begin(),
            previous.end()
        );
    }
};
