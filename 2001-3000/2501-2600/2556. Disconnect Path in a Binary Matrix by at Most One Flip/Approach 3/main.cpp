class Solution {
    bool removePath(
        vector<vector<int>>& grid,
        int row,
        int col
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        if (row >= rows ||
            col >= cols ||
            grid[row][col] == 0) {
            return false;
        }

        if (row == rows - 1 &&
            col == cols - 1) {
            return true;
        }

        grid[row][col] = 0;

        return
            removePath(
                grid,
                row + 1,
                col
            ) ||
            removePath(
                grid,
                row,
                col + 1
            );
    }

public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if (!removePath(
                grid,
                0,
                0)) {
            return true;
        }

        grid[0][0] = 1;

        return !removePath(
            grid,
            0,
            0
        );
    }
};
