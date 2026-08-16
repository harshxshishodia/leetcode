class Solution {
    int rows;
    int cols;
    vector<array<int, 10>> cost;

    int solve(
        int column,
        int previousDigit
    ) {
        if (column == cols) {
            return 0;
        }

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

        return answer;
    }

public:
    int minimumOperations(
        vector<vector<int>>& grid
    ) {
        rows =
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

        return solve(
            0,
            -1
        );
    }
};
