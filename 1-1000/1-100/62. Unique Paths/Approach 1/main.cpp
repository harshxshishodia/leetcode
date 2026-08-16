class Solution {
    int solve(int row, int col, int rows, int cols) {
        if (row == rows - 1 && col == cols - 1) {
            return 1;
        }

        if (row >= rows || col >= cols) {
            return 0;
        }

        return solve(row + 1, col, rows, cols) +
               solve(row, col + 1, rows, cols);
    }

public:
    int uniquePaths(int m, int n) {
        return solve(0, 0, m, n);
    }
};
