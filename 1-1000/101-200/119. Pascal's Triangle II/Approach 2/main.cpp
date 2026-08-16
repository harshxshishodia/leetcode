class Solution {
    long long combination(int n, int r) {
        r = min(r, n - r);
        long long result = 1;

        for (int i = 1; i <= r; i++) {
            result = result * (n - r + i) / i;
        }

        return result;
    }

public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;

        for (int col = 0; col <= rowIndex; col++) {
            row.push_back(static_cast<int>(combination(rowIndex, col)));
        }

        return row;
    }
};
