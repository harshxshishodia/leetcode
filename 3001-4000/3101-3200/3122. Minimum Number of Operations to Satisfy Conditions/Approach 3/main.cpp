class Solution {
public:
    int minimumOperations(
        vector<vector<int>>& grid
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<array<int, 10>> cost(
            cols
        );

        for (int column = 0;
             column < cols;
             column++) {
            for (int digit = 0;
                 digit <= 9;
                 digit++) {
                for (int row = 0;
                     row < rows;
                     row++) {
                    cost[column][digit] +=
                        grid[row][column] !=
                        digit;
                }
            }
        }

        vector<array<int, 10>> dp(
            cols
        );

        for (int digit = 0;
             digit <= 9;
             digit++) {
            dp[0][digit] =
                cost[0][digit];
        }

        for (int column = 1;
             column < cols;
             column++) {
            for (int digit = 0;
                 digit <= 9;
                 digit++) {
                dp[column][digit] =
                    numeric_limits<int>::max();

                for (int previous = 0;
                     previous <= 9;
                     previous++) {
                    if (previous == digit) {
                        continue;
                    }

                    dp[column][digit] = min(
                        dp[column][digit],
                        dp[column - 1][previous] +
                        cost[column][digit]
                    );
                }
            }
        }

        return *min_element(
            dp[cols - 1].begin(),
            dp[cols - 1].end()
        );
    }
};
