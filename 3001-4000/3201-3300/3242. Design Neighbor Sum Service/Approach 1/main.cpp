class NeighborSum {
    vector<vector<int>> matrix;
    int gridSize;

public:
    NeighborSum(vector<vector<int>>& grid) : matrix(grid), gridSize(static_cast<int>(grid.size())) {}

    int adjacentSum(int value) {
        int r = -1, c = -1;
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (matrix[i][j] == value) {
                    r = i;
                    c = j;
                    break;
                }
            }
            if (r != -1) break;
        }

        int sum = 0;
        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < gridSize && nc >= 0 && nc < gridSize) {
                sum += matrix[nr][nc];
            }
        }
        return sum;
    }

    int diagonalSum(int value) {
        int r = -1, c = -1;
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (matrix[i][j] == value) {
                    r = i;
                    c = j;
                    break;
                }
            }
            if (r != -1) break;
        }

        int sum = 0;
        const int dr[] = {-1, -1, 1, 1};
        const int dc[] = {-1, 1, -1, 1};
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < gridSize && nc >= 0 && nc < gridSize) {
                sum += matrix[nr][nc];
            }
        }
        return sum;
    }
};
