class Solution {
    vector<vector<int>> memo;

    int solve(int row, int column, int m, int n) {
        if (row == m - 1 && column == n - 1)
            return 1;

        if (row >= m || column >= n)
            return 0;

        if (memo[row][column] != -1)
            return memo[row][column];

        return memo[row][column] = solve(row + 1, column, m, n) + solve(row, column + 1, m, n);
    }

public:
    int uniquePaths(int m, int n) {
        memo.assign(m, vector<int>(n, -1));
        return solve(0, 0, m, n);
    }
};