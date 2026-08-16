class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> previous = {1};

        for (int row = 1; row <= rowIndex; row++) {
            vector<int> current(row + 1, 1);

            for (int col = 1; col < row; col++) {
                current[col] = previous[col - 1] + previous[col];
            }

            previous = current;
        }

        return previous;
    }
};
