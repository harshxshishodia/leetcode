class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int row = 0; row < numRows; row++) {
            vector<int> current(row + 1);
            long long value = 1;
            current[0] = 1;

            for (int col = 1; col <= row; col++) {
                value = value * (row - col + 1) / col;
                current[col] = static_cast<int>(value);
            }

            triangle.push_back(current);
        }

        return triangle;
    }
};
