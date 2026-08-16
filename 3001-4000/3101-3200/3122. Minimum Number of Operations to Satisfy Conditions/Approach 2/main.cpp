class Solution {
    int cols;
    vector<array<int, 10>> cost;
    vector<array<int, 11>> memo;
    vector<array<bool, 11>> visited;

    int solve(
        int column,
        int previousDigit
    ) {
        if (column == cols) {
            return 0;
        }

        int state =
            previousDigit +
            1;

        if (visited[column][state]) {
            return memo[column][state];
        }

        visited[column][state] =
            true;

        int answer =
            numeric_limits<int>::max();

        for (int digit = 0;
             digit <= 9;
             digit++) {
            if (digit == previousDigit) {
                continue;
            }

            answer = min(
                answer,
                cost[column][digit] +
                solve(
                    column + 1,
                    digit
                )
            );
        }

        memo[column][state] =
            answer;

        return answer;
    }

public:
    int minimumOperations(
        vector<vector<int>>& grid
    ) {
        int rows =
            static_cast<int>(grid.size());

        cols =
            static_cast<int>(grid[0].size());

        cost.assign(
            cols,
            {}
        );

        for (int column = 0;
             column < cols;
             column++) {
            for (int digit = 0;
                 digit <= 9;
                 digit++) {
                int changes = 0;

                for (int row = 0;
                     row < rows;
                     row++) {
                    changes +=
                        grid[row][column] !=
                        digit;
                }

                cost[column][digit] =
                    changes;
            }
        }

        memo.assign(
            cols,
            {}
        );

        visited.assign(
            cols,
            {}
        );

        return solve(
            0,
            -1
        );
    }
};
