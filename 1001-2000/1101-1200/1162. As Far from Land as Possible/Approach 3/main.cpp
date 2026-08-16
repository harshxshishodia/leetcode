class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n =
            static_cast<int>(grid.size());

        const int INF =
            1000000000;

        vector<vector<int>> distance(
            n,
            vector<int>(
                n,
                INF
            )
        );

        bool hasLand = false;
        bool hasWater = false;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    distance[row][col] = 0;
                    hasLand = true;
                } else {
                    hasWater = true;
                }
            }
        }

        if (!hasLand || !hasWater) {
            return -1;
        }

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
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

        for (int row = n - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {
                if (row + 1 < n) {
                    distance[row][col] = min(
                        distance[row][col],
                        distance[row + 1][col] + 1
                    );
                }

                if (col + 1 < n) {
                    distance[row][col] = min(
                        distance[row][col],
                        distance[row][col + 1] + 1
                    );
                }
            }
        }

        int answer = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    answer = max(
                        answer,
                        distance[row][col]
                    );
                }
            }
        }

        return answer;
    }
};
