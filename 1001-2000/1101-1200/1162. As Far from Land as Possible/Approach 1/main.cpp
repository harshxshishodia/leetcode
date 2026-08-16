class Solution {
    int distanceToLand(
        const vector<vector<int>>& grid,
        int startRow,
        int startCol
    ) {
        int n =
            static_cast<int>(grid.size());

        if (grid[startRow][startCol] == 1) {
            return 0;
        }

        vector<vector<bool>> visited(
            n,
            vector<bool>(n)
        );

        queue<pair<int, int>> pending;

        pending.push({
            startRow,
            startCol
        });

        visited[startRow][startCol] = true;

        array<int, 4> rowChange = {-1, 1, 0, 0};
        array<int, 4> colChange = {0, 0, -1, 1};

        int distance = 0;

        while (!pending.empty()) {
            int levelSize =
                static_cast<int>(pending.size());

            distance++;

            for (int i = 0; i < levelSize; i++) {
                auto [row, col] =
                    pending.front();

                pending.pop();

                for (int direction = 0; direction < 4; direction++) {
                    int nextRow =
                        row + rowChange[direction];

                    int nextCol =
                        col + colChange[direction];

                    if (nextRow < 0 ||
                        nextRow >= n ||
                        nextCol < 0 ||
                        nextCol >= n ||
                        visited[nextRow][nextCol]) {
                        continue;
                    }

                    if (grid[nextRow][nextCol] == 1) {
                        return distance;
                    }

                    visited[nextRow][nextCol] = true;

                    pending.push({
                        nextRow,
                        nextCol
                    });
                }
            }
        }

        return -1;
    }

public:
    int maxDistance(vector<vector<int>>& grid) {
        int n =
            static_cast<int>(grid.size());

        int answer = -1;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    answer = max(
                        answer,
                        distanceToLand(
                            grid,
                            row,
                            col
                        )
                    );
                }
            }
        }

        return answer;
    }
};
