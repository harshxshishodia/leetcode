class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        row[0] = 1;

        for (int current = 1; current <= rowIndex; current++) {
            for (int col = current; col > 0; col--) {
                row[col] += row[col - 1];
            }
        }

        return row;
    }
};
