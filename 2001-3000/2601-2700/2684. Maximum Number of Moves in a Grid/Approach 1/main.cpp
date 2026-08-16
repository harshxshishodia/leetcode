class Solution {
    int solve(
        const vector<vector<int>>& grid,
        int row,
        int col
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        if (col == cols - 1) {
            return 0;
        }

        int answer = 0;

        for (int nextRow =
                 max(
                     0,
                     row - 1
                 );
             nextRow <=
                 min(
                     rows - 1,
                     row + 1
                 );
             nextRow++) {
            if (grid[nextRow][col + 1] >
                grid[row][col]) {
                answer = max(
                    answer,
                    1 +
                    solve(
                        grid,
                        nextRow,
                        col + 1
                    )
                );
            }
        }

        return answer;
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        int answer = 0;

        for (int row = 0;
             row < static_cast<int>(grid.size());
             row++) {
            answer = max(
                answer,
                solve(
                    grid,
                    row,
                    0
                )
            );
        }

        return answer;
    }
};
