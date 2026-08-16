class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        vector<vector<int>> prefix(
            rows + 1,
            vector<int>(cols + 1)
        );

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                prefix[row + 1][col + 1] =
                    prefix[row][col + 1] +
                    prefix[row + 1][col] -
                    prefix[row][col] +
                    (matrix[row][col] - '0');
            }
        }

        int bestSide = 0;

        for (int top = 0; top < rows; top++) {
            for (int left = 0; left < cols; left++) {
                int maximumSide = min(rows - top, cols - left);

                for (int side = bestSide + 1; side <= maximumSide; side++) {
                    int bottom = top + side;
                    int right = left + side;

                    int ones =
                        prefix[bottom][right] -
                        prefix[top][right] -
                        prefix[bottom][left] +
                        prefix[top][left];

                    if (ones == side * side) {
                        bestSide = side;
                    }
                }
            }
        }

        return bestSide * bestSide;
    }
};
