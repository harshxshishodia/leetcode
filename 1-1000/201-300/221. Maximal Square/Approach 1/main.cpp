class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        int bestSide = 0;

        for (int top = 0; top < rows; top++) {
            for (int left = 0; left < cols; left++) {
                int maximumSide = min(rows - top, cols - left);

                for (int side = 1; side <= maximumSide; side++) {
                    bool valid = true;

                    for (int row = top; row < top + side && valid; row++) {
                        for (int col = left; col < left + side; col++) {
                            if (matrix[row][col] == '0') {
                                valid = false;
                                break;
                            }
                        }
                    }

                    if (valid) {
                        bestSide = max(bestSide, side);
                    }
                }
            }
        }

        return bestSide * bestSide;
    }
};
