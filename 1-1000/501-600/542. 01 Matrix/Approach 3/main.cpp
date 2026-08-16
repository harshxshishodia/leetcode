class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = static_cast<int>(mat.size());
        int cols = static_cast<int>(mat[0].size());
        int infinity = rows + cols + 1;

        vector<vector<int>> distance(
            rows,
            vector<int>(cols, infinity)
        );

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (mat[row][col] == 0) {
                    distance[row][col] = 0;
                    continue;
                }

                if (row > 0) {
                    distance[row][col] = min(
                        distance[row][col],
                        distance[row - 1][col] + 1
                    );
                }

                if (col > 0) {
                    distance[row][col] = min(
                        distance[row][col],
                        distance[row][col - 1] + 1
                    );
                }
            }
        }

        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                if (row + 1 < rows) {
                    distance[row][col] = min(
                        distance[row][col],
                        distance[row + 1][col] + 1
                    );
                }

                if (col + 1 < cols) {
                    distance[row][col] = min(
                        distance[row][col],
                        distance[row][col + 1] + 1
                    );
                }
            }
        }

        return distance;
    }
};
