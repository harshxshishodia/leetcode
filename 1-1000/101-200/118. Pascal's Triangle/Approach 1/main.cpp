class Solution {
    int value(int row, int col) {
        if (col == 0 || col == row) {
            return 1;
        }

        return value(row - 1, col - 1) + value(row - 1, col);
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int row = 0; row < numRows; row++) {
            vector<int> current;

            for (int col = 0; col <= row; col++) {
                current.push_back(value(row, col));
            }

            triangle.push_back(current);
        }

        return triangle;
    }
};
