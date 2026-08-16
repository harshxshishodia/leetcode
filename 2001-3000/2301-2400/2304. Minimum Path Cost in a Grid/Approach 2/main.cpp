class Solution {
    vector<vector<int>> memo;

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

        if (memo[row][col] != -1) {
            return memo[row][col];
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

        memo[row][col] =
            answer;

        return memo[row][col];
    }

public:
    int minPathCost(
        vector<vector<int>>& grid,
        vector<vector<int>>& moveCost
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        memo.assign(
            rows,
            vector<int>(
                cols,
                -1
            )
        );

        int answer =
            numeric_limits<int>::max();

        for (int col = 0; col < cols; col++) {
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
