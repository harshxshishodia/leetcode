class Solution {
    int distanceToZero(
        const vector<vector<int>>& mat,
        int startRow,
        int startCol
    ) {
        if (mat[startRow][startCol] == 0) {
            return 0;
        }

        int rows = static_cast<int>(mat.size());
        int cols = static_cast<int>(mat[0].size());

        queue<pair<int, int>> pending;
        vector<vector<bool>> visited(
            rows,
            vector<bool>(cols)
        );

        pending.push({startRow, startCol});
        visited[startRow][startCol] = true;
        int distance = 0;

        array<int, 4> rowChange = {-1, 1, 0, 0};
        array<int, 4> colChange = {0, 0, -1, 1};

        while (!pending.empty()) {
            int levelSize = static_cast<int>(pending.size());
            distance++;

            for (int i = 0; i < levelSize; i++) {
                auto [row, col] = pending.front();
                pending.pop();

                for (int direction = 0; direction < 4; direction++) {
                    int nextRow = row + rowChange[direction];
                    int nextCol = col + colChange[direction];

                    if (nextRow < 0 ||
                        nextRow >= rows ||
                        nextCol < 0 ||
                        nextCol >= cols ||
                        visited[nextRow][nextCol]) {
                        continue;
                    }

                    if (mat[nextRow][nextCol] == 0) {
                        return distance;
                    }

                    visited[nextRow][nextCol] = true;
                    pending.push({nextRow, nextCol});
                }
            }
        }

        return distance;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = static_cast<int>(mat.size());
        int cols = static_cast<int>(mat[0].size());
        vector<vector<int>> answer(
            rows,
            vector<int>(cols)
        );

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                answer[row][col] =
                    distanceToZero(mat, row, col);
            }
        }

        return answer;
    }
};
