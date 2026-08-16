class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n =
            static_cast<int>(grid.size());

        queue<pair<int, int>> pending;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    pending.push({
                        row,
                        col
                    });
                }
            }
        }

        if (pending.empty() ||
            static_cast<int>(pending.size()) == n * n) {
            return -1;
        }

        array<int, 4> rowChange = {-1, 1, 0, 0};
        array<int, 4> colChange = {0, 0, -1, 1};

        int distance = -1;

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
                        grid[nextRow][nextCol] != 0) {
                        continue;
                    }

                    grid[nextRow][nextCol] = 1;

                    pending.push({
                        nextRow,
                        nextCol
                    });
                }
            }
        }

        return distance;
    }
};
