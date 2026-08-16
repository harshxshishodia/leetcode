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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int row = 0; row < numRows; row++) {
            vector<int> current;

            for (int col = 0; col <= row; col++) {
                current.push_back(static_cast<int>(combination(row, col)));
            }

            triangle.push_back(current);
        }

        return triangle;
    }
};
