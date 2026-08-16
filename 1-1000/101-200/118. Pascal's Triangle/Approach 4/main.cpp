class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);

        for (int row = 0; row < numRows; row++) {
            triangle[row].resize(row + 1, 1);

            for (int col = 1; col < row; col++) {
                triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
            }
        }

        return triangle;
    }
};
