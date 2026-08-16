class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        long long value = 1;
        row[0] = 1;

        for (int col = 1; col <= rowIndex; col++) {
            value = value * (rowIndex - col + 1) / col;
            row[col] = static_cast<int>(value);
        }

        return row;
    }
};
