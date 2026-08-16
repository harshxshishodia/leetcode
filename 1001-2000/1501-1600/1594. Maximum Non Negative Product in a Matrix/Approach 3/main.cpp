class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD =
            1000000007;

        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<vector<long long>> minimum(
            rows,
            vector<long long>(cols)
        );

        vector<vector<long long>> maximum(
            rows,
            vector<long long>(cols)
        );

        minimum[0][0] =
            maximum[0][0] =
            grid[0][0];

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row == 0 && col == 0) {
                    continue;
                }

                long long low =
                    numeric_limits<long long>::max();

                long long high =
                    numeric_limits<long long>::min();

                if (row > 0) {
                    long long first =
                        minimum[row - 1][col] *
                        grid[row][col];

                    long long second =
                        maximum[row - 1][col] *
                        grid[row][col];

                    low = min({
                        low,
                        first,
                        second
                    });

                    high = max({
                        high,
                        first,
                        second
                    });
                }

                if (col > 0) {
                    long long first =
                        minimum[row][col - 1] *
                        grid[row][col];

                    long long second =
                        maximum[row][col - 1] *
                        grid[row][col];

                    low = min({
                        low,
                        first,
                        second
                    });

                    high = max({
                        high,
                        first,
                        second
                    });
                }

                minimum[row][col] = low;
                maximum[row][col] = high;
            }
        }

        long long answer =
            maximum[rows - 1][cols - 1];

        if (answer < 0) {
            return -1;
        }

        return static_cast<int>(
            answer % MOD
        );
    }
};
