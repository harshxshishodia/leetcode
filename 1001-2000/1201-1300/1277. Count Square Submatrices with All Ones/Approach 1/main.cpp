class Solution {
    bool allOnes(
        const vector<vector<int>>& matrix,
        int top,
        int left,
        int side
    ) {
        for (int row = top; row < top + side; row++) {
            for (int col = left; col < left + side; col++) {
                if (matrix[row][col] == 0) {
                    return false;
                }
            }
        }

        return true;
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        int answer = 0;

        for (int top = 0; top < rows; top++) {
            for (int left = 0; left < cols; left++) {
                int maximumSide = min(
                    rows - top,
                    cols - left
                );

                for (int side = 1; side <= maximumSide; side++) {
                    if (allOnes(
                            matrix,
                            top,
                            left,
                            side)) {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }
};
