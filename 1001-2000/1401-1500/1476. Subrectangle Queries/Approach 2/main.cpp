class SubrectangleQueries {
    struct UpdateRecord {
        int r1, c1, r2, c2, value;
    };

    vector<vector<int>> initialMatrix;
    vector<UpdateRecord> updateHistory;

public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : initialMatrix(rectangle) {}

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        updateHistory.push_back({row1, col1, row2, col2, newValue});
    }

    int getValue(int row, int col) {
        for (int i = static_cast<int>(updateHistory.size()) - 1; i >= 0; i--) {
            const auto& update = updateHistory[i];
            if (row >= update.r1 && row <= update.r2 && col >= update.c1 && col <= update.c2) {
                return update.value;
            }
        }
        return initialMatrix[row][col];
    }
};
