class NumMatrix {
    vector<vector<int>> tree;
    vector<vector<int>> matrixGrid;
    int m, n;

    void addDelta(int r, int c, int delta) {
        for (int i = r; i <= m; i += i & (-i)) {
            for (int j = c; j <= n; j += j & (-j)) {
                tree[i][j] += delta;
            }
        }
    }

    int queryPrefix(int r, int c) {
        int sum = 0;
        for (int i = r; i > 0; i -= i & (-i)) {
            for (int j = c; j > 0; j -= j & (-j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        m = static_cast<int>(matrix.size());
        n = static_cast<int>(matrix[0].size());
        matrixGrid = matrix;
        tree.assign(m + 1, vector<int>(n + 1, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                addDelta(r + 1, c + 1, matrix[r][c]);
            }
        }
    }

    void update(int row, int col, int val) {
        int delta = val - matrixGrid[row][col];
        matrixGrid[row][col] = val;
        addDelta(row + 1, col + 1, delta);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return queryPrefix(row2 + 1, col2 + 1) - queryPrefix(row1, col2 + 1) - queryPrefix(row2 + 1, col1) + queryPrefix(row1, col1);
    }
};
