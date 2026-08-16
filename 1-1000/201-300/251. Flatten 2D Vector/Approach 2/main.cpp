class Vector2D {
    vector<vector<int>> matrix;
    int row;
    int col;

    void advanceToNextValid() {
        while (row < static_cast<int>(matrix.size()) && col == static_cast<int>(matrix[row].size())) {
            row++;
            col = 0;
        }
    }

public:
    Vector2D(vector<vector<int>>& vec) : matrix(vec), row(0), col(0) {}

    int next() {
        advanceToNextValid();
        return matrix[row][col++];
    }

    bool hasNext() {
        advanceToNextValid();
        return row < static_cast<int>(matrix.size());
    }
};
