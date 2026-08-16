class SubrectangleQueries {
    vector<vector<int>> matrix;

public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : matrix(rectangle) {}

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int r = row1; r <= row2; r++) {
            for (int c = col1; c <= col2; c++) {
                matrix[r][c] = newValue;
            }
        }
    }

    int getValue(int row, int col) {
        return matrix[row][col];
    }
};
