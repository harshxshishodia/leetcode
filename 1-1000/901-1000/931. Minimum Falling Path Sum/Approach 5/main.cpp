class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = static_cast<int>(matrix.size());

        for (int row = 1; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int best =
                    matrix[row - 1][col];

                if (col > 0) {
                    best = min(
                        best,
                        matrix[row - 1][col - 1]
                    );
                }

                if (col + 1 < n) {
                    best = min(
                        best,
                        matrix[row - 1][col + 1]
                    );
                }

                matrix[row][col] += best;
            }
        }

        return *min_element(
            matrix[n - 1].begin(),
            matrix[n - 1].end()
        );
    }
};
