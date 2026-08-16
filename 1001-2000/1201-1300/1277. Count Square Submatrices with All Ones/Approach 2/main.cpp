class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());

        vector<vector<int>> prefix(
            rows + 1,
            vector<int>(cols + 1)
        );

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                prefix[row + 1][col + 1] =
                    matrix[row][col] +
                    prefix[row][col + 1] +
                    prefix[row + 1][col] -
                    prefix[row][col];
            }
        }

        int answer = 0;

        for (int top = 0; top < rows; top++) {
            for (int left = 0; left < cols; left++) {
                int maximumSide = min(
                    rows - top,
                    cols - left
                );

                for (int side = 1; side <= maximumSide; side++) {
                    int bottom = top + side;
                    int right = left + side;

                    int sum =
                        prefix[bottom][right] -
                        prefix[top][right] -
                        prefix[bottom][left] +
                        prefix[top][left];

                    if (sum == side * side) {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }
};
