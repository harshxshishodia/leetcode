class NumMatrix {
    vector<vector<int>> matrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
    }

    void update(int row, int col, int val) {
        matrix[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        for (int row = row1; row <= row2; row++) {
            for (int col = col1; col <= col2; col++)
                sum += matrix[row][col];
        }

        return sum;
    }
};