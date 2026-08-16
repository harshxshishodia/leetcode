class NeighborSum {
    vector<vector<int>> matrixGrid;
    unordered_map<int, pair<int, int>> positionMap;
    int size;

public:
    NeighborSum(vector<vector<int>>& grid) : matrixGrid(grid), size(static_cast<int>(grid.size())) {
        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                positionMap[grid[r][c]] = {r, c};
            }
        }
    }

    int adjacentSum(int value) {
        auto [row, col] = positionMap[value];
        int sum = 0;
        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
                sum += matrixGrid[newRow][newCol];
            }
        }
        return sum;
    }

    int diagonalSum(int value) {
        auto [row, col] = positionMap[value];
        int sum = 0;
        const int dr[] = {-1, -1, 1, 1};
        const int dc[] = {-1, 1, -1, 1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
                sum += matrixGrid[newRow][newCol];
            }
        }
        return sum;
    }
};
