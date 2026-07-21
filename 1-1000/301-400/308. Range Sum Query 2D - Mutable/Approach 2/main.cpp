class NumMatrix {
    vector<vector<int>> matrix;
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix.assign(rows, vector<int>(cols + 1, 0));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++)
                prefix[row][col + 1] = prefix[row][col] + matrix[row][col];
        }
    }

    void update(int row, int col, int val) {
        int difference = val - matrix[row][col];
        matrix[row][col] = val;

        for (int currentCol = col + 1; currentCol < prefix[row].size(); currentCol++)
            prefix[row][currentCol] += difference;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        for (int row = row1; row <= row2; row++)
            sum += prefix[row][col2 + 1] - prefix[row][col1];

        return sum;
    }
};