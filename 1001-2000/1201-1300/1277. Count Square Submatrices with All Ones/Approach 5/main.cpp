class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        int answer = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) {
                    continue;
                }

                if (row > 0 && col > 0) {
                    matrix[row][col] += min({
                        matrix[row - 1][col],
                        matrix[row][col - 1],
                        matrix[row - 1][col - 1]
                    });
                }

                answer += matrix[row][col];
            }
        }

        return answer;
    }
};
