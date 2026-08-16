class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows =
            static_cast<int>(points.size());

        int cols =
            static_cast<int>(points[0].size());

        vector<long long> previous(
            cols
        );

        for (int col = 0; col < cols; col++) {
            previous[col] =
                points[0][col];
        }

        for (int row = 1; row < rows; row++) {
            vector<long long> left(cols);
            vector<long long> right(cols);
            vector<long long> current(cols);

            left[0] =
                previous[0];

            for (int col = 1; col < cols; col++) {
                left[col] = max(
                    previous[col],
                    left[col - 1] - 1
                );
            }

            right[cols - 1] =
                previous[cols - 1];

            for (int col = cols - 2; col >= 0; col--) {
                right[col] = max(
                    previous[col],
                    right[col + 1] - 1
                );
            }

            for (int col = 0; col < cols; col++) {
                current[col] =
                    points[row][col] +
                    max(
                        left[col],
                        right[col]
                    );
            }

            previous = current;
        }

        return *max_element(
            previous.begin(),
            previous.end()
        );
    }
};
