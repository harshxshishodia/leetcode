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
            for (int col = 0; col < cols; col++) {
                long long best =
                    numeric_limits<long long>::min();

                for (int previous = 0;
                     previous < cols;
                     previous++) {
                    best = max(
                        best,
                        dp[row - 1][previous] -
                        abs(col - previous)
                    );
                }

                dp[row][col] =
                    points[row][col] +
                    best;
            }
        }

        return *max_element(
            dp[rows - 1].begin(),
            dp[rows - 1].end()
        );
    }
};
