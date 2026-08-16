class Solution {
    int solve(
        const vector<vector<char>>& matrix,
        int row,
        int col,
        vector<vector<int>>& memo
    ) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());

        if (row >= rows || col >= cols || matrix[row][col] == '0') {
            return 0;
        }

        if (memo[row][col] != -1) {
            return memo[row][col];
        }

        int down = solve(matrix, row + 1, col, memo);
        int right = solve(matrix, row, col + 1, memo);
        int diagonal = solve(matrix, row + 1, col + 1, memo);

        memo[row][col] = 1 + min({down, right, diagonal});
        return memo[row][col];
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        vector<vector<int>> memo(rows, vector<int>(cols, -1));
        int bestSide = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                bestSide = max(
                    bestSide,
                    solve(matrix, row, col, memo)
                );
            }
        }

        return bestSide * bestSide;
    }
};
