class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD =
            1000000007;

        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<long long> minimum(cols);
        vector<long long> maximum(cols);

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row == 0 && col == 0) {
                    minimum[col] =
                        maximum[col] =
                        grid[row][col];

                    continue;
                }

                long long low =
                    numeric_limits<long long>::max();

                long long high =
                    numeric_limits<long long>::min();

                if (row > 0) {
                    long long first =
                        minimum[col] *
                        grid[row][col];

                    long long second =
                        maximum[col] *
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
                        minimum[col - 1] *
                        grid[row][col];

                    long long second =
                        maximum[col - 1] *
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

                minimum[col] = low;
                maximum[col] = high;
            }
        }

        long long answer =
            maximum[cols - 1];

        if (answer < 0) {
            return -1;
        }

        return static_cast<int>(
            answer % MOD
        );
    }
};
