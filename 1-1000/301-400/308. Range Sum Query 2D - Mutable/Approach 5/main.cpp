class NumMatrix {
    vector<vector<int>> tree;
    int rows;
    int cols;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        tree.assign(rows * 2, vector<int>(cols * 2, 0));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++)
                tree[row + rows][col + cols] = matrix[row][col];
        }

        for (int row = rows; row < rows * 2; row++) {
            for (int col = cols - 1; col > 0; col--)
                tree[row][col] = tree[row][col * 2] + tree[row][col * 2 + 1];
        }

        for (int row = rows - 1; row > 0; row--) {
            for (int col = 1; col < cols * 2; col++)
                tree[row][col] = tree[row * 2][col] + tree[row * 2 + 1][col];
        }
    }

    void update(int row, int col, int val) {
        int rowIndex = row + rows;
        int colIndex = col + cols;
        tree[rowIndex][colIndex] = val;

        for (int currentCol = colIndex; currentCol > 1; currentCol /= 2) {
            int parentCol = currentCol / 2;
            tree[rowIndex][parentCol] = tree[rowIndex][parentCol * 2] + tree[rowIndex][parentCol * 2 + 1];
        }

        for (int currentRow = rowIndex; currentRow > 1; currentRow /= 2) {
            int parentRow = currentRow / 2;

            for (int currentCol = colIndex; currentCol > 0; currentCol /= 2)
                tree[parentRow][currentCol] = tree[parentRow * 2][currentCol] + tree[parentRow * 2 + 1][currentCol];
        }
    }

    int queryColumns(int row, int left, int right) {
        int sum = 0;
        left += cols;
        right += cols;

        while (left <= right) {
            if (left % 2 == 1) {
                sum += tree[row][left];
                left++;
            }

            if (right % 2 == 0) {
                sum += tree[row][right];
                right--;
            }

            left /= 2;
            right /= 2;
        }

        return sum;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        row1 += rows;
        row2 += rows;

        while (row1 <= row2) {
            if (row1 % 2 == 1) {
                sum += queryColumns(row1, col1, col2);
                row1++;
            }

            if (row2 % 2 == 0) {
                sum += queryColumns(row2, col1, col2);
                row2--;
            }

            row1 /= 2;
            row2 /= 2;
        }

        return sum;
    }
};