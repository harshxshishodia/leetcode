class Solution {
    int solve(int row, int column, int m, int n) {
        if (row == m - 1 && column == n - 1)
            return 1;

        if (row >= m || column >= n)
            return 0;

        return solve(row + 1, column, m, n) + solve(row, column + 1, m, n);
    }

public:
    int uniquePaths(int m, int n) {
        return solve(0, 0, m, n);
    }
};