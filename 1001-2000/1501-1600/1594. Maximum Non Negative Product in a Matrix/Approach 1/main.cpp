class Solution {
    long long best;

    void search(
        const vector<vector<int>>& grid,
        int row,
        int col,
        long long product
    ) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        product *=
            grid[row][col];

        if (row == rows - 1 &&
            col == cols - 1) {
            if (product >= 0) {
                best = max(
                    best,
                    product
                );
            }

            return;
        }

        if (row + 1 < rows) {
            search(
                grid,
                row + 1,
                col,
                product
            );
        }

        if (col + 1 < cols) {
            search(
                grid,
                row,
                col + 1,
                product
            );
        }
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD =
            1000000007;

        best = -1;

        search(
            grid,
            0,
            0,
            1
        );

        if (best < 0) {
            return -1;
        }

        return static_cast<int>(
            best % MOD
        );
    }
};
