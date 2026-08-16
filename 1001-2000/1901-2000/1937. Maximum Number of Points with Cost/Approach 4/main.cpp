class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows =
            static_cast<int>(points.size());

        int cols =
            static_cast<int>(points[0].size());

        vector<vector<long long>> dp(
            rows,
            vector<long long>(cols)
        );

        for (int col = 0; col < cols; col++) {
            dp[0][col] =
                points[0][col];
        }

        for (int row = 1; row < rows; row++) {
            vector<long long> left(cols);
            vector<long long> right(cols);

            left[0] =
                dp[row - 1][0];

            for (int col = 1; col < cols; col++) {
                left[col] = max(
                    dp[row - 1][col],
                    left[col - 1] - 1
                );
            }

            right[cols - 1] =
                dp[row - 1][cols - 1];

            for (int col = cols - 2; col >= 0; col--) {
                right[col] = max(
                    dp[row - 1][col],
                    right[col + 1] - 1
                );
            }

            for (int col = 0; col < cols; col++) {
                dp[row][col] =
                    points[row][col] +
                    max(
                        left[col],
                        right[col]
                    );
            }
        }

        return *max_element(
            dp[rows - 1].begin(),
            dp[rows - 1].end()
        );
    }
};
