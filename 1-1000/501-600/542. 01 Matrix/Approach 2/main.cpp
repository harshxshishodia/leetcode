class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = static_cast<int>(mat.size());
        int cols = static_cast<int>(mat[0].size());
        vector<vector<int>> distance(
            rows,
            vector<int>(cols, -1)
        );

        queue<pair<int, int>> pending;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (mat[row][col] == 0) {
                    distance[row][col] = 0;
                    pending.push({row, col});
                }
            }
        }

        array<int, 4> rowChange = {-1, 1, 0, 0};
        array<int, 4> colChange = {0, 0, -1, 1};

        while (!pending.empty()) {
            auto [row, col] = pending.front();
            pending.pop();

            for (int direction = 0; direction < 4; direction++) {
                int nextRow = row + rowChange[direction];
                int nextCol = col + colChange[direction];

                if (nextRow < 0 ||
                    nextRow >= rows ||
                    nextCol < 0 ||
                    nextCol >= cols ||
                    distance[nextRow][nextCol] != -1) {
                    continue;
                }

                distance[nextRow][nextCol] =
                    distance[row][col] + 1;

                pending.push({nextRow, nextCol});
            }
        }

        return distance;
    }
};
