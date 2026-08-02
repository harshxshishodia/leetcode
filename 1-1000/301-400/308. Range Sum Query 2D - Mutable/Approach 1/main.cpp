class NumMatrix {
    vector<vector<int>> segmentTree;
    vector<vector<int>> matrixData;
    int rows, cols;
    void buildColTree(int rowNode, int colNode, int colLeft, int colRight, int rowIndex, bool isLeafRow) {
        if (colLeft == colRight) {
            if (isLeafRow) {
                segmentTree[rowNode][colNode] = matrixData[rowIndex][colLeft];
            } else {
                segmentTree[rowNode][colNode] = segmentTree[2 * rowNode + 1][colNode] + segmentTree[2 * rowNode + 2][colNode];
            }
            return;
        }
        int colMid = colLeft + (colRight - colLeft) / 2;
        buildColTree(rowNode, 2 * colNode + 1, colLeft, colMid, rowIndex, isLeafRow);
        buildColTree(rowNode, 2 * colNode + 2, colMid + 1, colRight, rowIndex, isLeafRow);
        segmentTree[rowNode][colNode] = segmentTree[rowNode][2 * colNode + 1] + segmentTree[rowNode][2 * colNode + 2];
    }
    void buildRowTree(int rowNode, int rowLeft, int rowRight) {
        if (rowLeft == rowRight) {
            buildColTree(rowNode, 0, 0, cols - 1, rowLeft, true);
            return;
        }
        int rowMid = rowLeft + (rowRight - rowLeft) / 2;
        buildRowTree(2 * rowNode + 1, rowLeft, rowMid);
        buildRowTree(2 * rowNode + 2, rowMid + 1, rowRight);
        buildColTree(rowNode, 0, 0, cols - 1, rowLeft, false);
    }
    void updateColTree(int rowNode, int colNode, int colLeft, int colRight, int updateCol, int value, bool isLeafRow) {
        if (colLeft == colRight) {
            if (isLeafRow) {
                segmentTree[rowNode][colNode] = value;
            } else {
                segmentTree[rowNode][colNode] = segmentTree[2 * rowNode + 1][colNode] + segmentTree[2 * rowNode + 2][colNode];
            }
            return;
        }
        int colMid = colLeft + (colRight - colLeft) / 2;
        if (updateCol <= colMid) {
            updateColTree(rowNode, 2 * colNode + 1, colLeft, colMid, updateCol, value, isLeafRow);
        } else {
            updateColTree(rowNode, 2 * colNode + 2, colMid + 1, colRight, updateCol, value, isLeafRow);
        }
        segmentTree[rowNode][colNode] = segmentTree[rowNode][2 * colNode + 1] + segmentTree[rowNode][2 * colNode + 2];
    }
    void updateRowTree(int rowNode, int rowLeft, int rowRight, int updateRow, int updateCol, int value) {
        if (rowLeft == rowRight) {
            updateColTree(rowNode, 0, 0, cols - 1, updateCol, value, true);
            return;
        }
        int rowMid = rowLeft + (rowRight - rowLeft) / 2;
        if (updateRow <= rowMid) {
            updateRowTree(2 * rowNode + 1, rowLeft, rowMid, updateRow, updateCol, value);
        } else {
            updateRowTree(2 * rowNode + 2, rowMid + 1, rowRight, updateRow, updateCol, value);
        }
        updateColTree(rowNode, 0, 0, cols - 1, updateCol, value, false);
    }
    int queryColTree(int rowNode, int colNode, int colLeft, int colRight, int queryColLeft, int queryColRight) {
        if (colLeft > queryColRight || colRight < queryColLeft) {
            return 0;
        }
        if (colLeft >= queryColLeft && colRight <= queryColRight) {
            return segmentTree[rowNode][colNode];
        }
        int colMid = colLeft + (colRight - colLeft) / 2;
        return queryColTree(rowNode, 2 * colNode + 1, colLeft, colMid, queryColLeft, queryColRight) +
               queryColTree(rowNode, 2 * colNode + 2, colMid + 1, colRight, queryColLeft, queryColRight);
    }
    int queryRowTree(int rowNode, int rowLeft, int rowRight, int queryRowLeft, int queryRowRight, int queryColLeft, int queryColRight) {
        if (rowLeft > queryRowRight || rowRight < queryRowLeft) {
            return 0;
        }
        if (rowLeft >= queryRowLeft && rowRight <= queryRowRight) {
            return queryColTree(rowNode, 0, 0, cols - 1, queryColLeft, queryColRight);
        }
        int rowMid = rowLeft + (rowRight - rowLeft) / 2;
        return queryRowTree(2 * rowNode + 1, rowLeft, rowMid, queryRowLeft, queryRowRight, queryColLeft, queryColRight) +
               queryRowTree(2 * rowNode + 2, rowMid + 1, rowRight, queryRowLeft, queryRowRight, queryColLeft, queryColRight);
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        rows = matrix.size();
        cols = matrix[0].size();
        matrixData = matrix;
        segmentTree.assign(4 * rows, vector<int>(4 * cols, 0));
        buildRowTree(0, 0, rows - 1);
    }
    void update(int row, int col, int val) {
        if (rows == 0 || cols == 0) return;
        updateRowTree(0, 0, rows - 1, row, col, val);
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (rows == 0 || cols == 0) return 0;
        return queryRowTree(0, 0, rows - 1, row1, row2, col1, col2);
    }
};
