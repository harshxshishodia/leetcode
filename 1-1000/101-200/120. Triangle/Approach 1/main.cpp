class Solution {
    int solve(const vector<vector<int>>& triangle, int row, int col) {
        if (row == static_cast<int>(triangle.size()) - 1) {
            return triangle[row][col];
        }

        int down = solve(triangle, row + 1, col);
        int diagonal = solve(triangle, row + 1, col + 1);

        return triangle[row][col] + min(down, diagonal);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle, 0, 0);
    }
};
