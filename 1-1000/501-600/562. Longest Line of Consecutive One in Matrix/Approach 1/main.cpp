class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return 0;
        }

        int rows = static_cast<int>(mat.size());
        int cols = static_cast<int>(mat[0].size());
        int answer = 0;

        array<int, 4> rowChange = {0, 1, 1, 1};
        array<int, 4> colChange = {1, 0, 1, -1};

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (mat[row][col] == 0) {
                    continue;
                }

                for (int direction = 0; direction < 4; direction++) {
                    int length = 0;
                    int currentRow = row;
                    int currentCol = col;

                    while (currentRow >= 0 &&
                           currentRow < rows &&
                           currentCol >= 0 &&
                           currentCol < cols &&
                           mat[currentRow][currentCol] == 1) {
                        length++;
                        currentRow += rowChange[direction];
                        currentCol += colChange[direction];
                    }

                    answer = max(answer, length);
                }
            }
        }

        return answer;
    }
};
