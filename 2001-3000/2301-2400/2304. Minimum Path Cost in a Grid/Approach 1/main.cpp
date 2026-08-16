class Solution {
    int solve(
        const vector<vector<int>>& grid,
        const vector<vector<int>>& moveCost,
        int row,
        int col
    ) {
        int rows =
            static_cast<int>(grid.size());

        if (row == rows - 1) {
            return grid[row][col];
        }

        int answer =
            numeric_limits<int>::max();

        for (int nextCol = 0;
             nextCol < static_cast<int>(grid[0].size());
             nextCol++) {
            answer = min(
                answer,
                grid[row][col] +
                moveCost[
                    grid[row][col]
                ][nextCol] +
                solve(
                    grid,
                    moveCost,
                    row + 1,
                    nextCol
                )
            );
        }

        return answer;
    }

public:
    int minPathCost(
        vector<vector<int>>& grid,
        vector<vector<int>>& moveCost
    ) {
        int answer =
            numeric_limits<int>::max();

        for (int col = 0;
             col < static_cast<int>(grid[0].size());
             col++) {
            answer = min(
                answer,
                solve(
                    grid,
                    moveCost,
                    0,
                    col
                )
            );
        }

        return answer;
    }
};
