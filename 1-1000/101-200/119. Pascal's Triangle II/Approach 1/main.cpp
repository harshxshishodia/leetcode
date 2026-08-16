class Solution {
    int value(int row, int col) {
        if (col == 0 || col == row) {
            return 1;
        }

        return value(row - 1, col - 1) + value(row - 1, col);
    }

public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;

        for (int col = 0; col <= rowIndex; col++) {
            row.push_back(value(rowIndex, col));
        }

        return row;
    }
};
