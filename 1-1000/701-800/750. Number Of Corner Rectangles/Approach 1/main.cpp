class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());
        int answer = 0;

        for (int firstRow = 0; firstRow < rows; firstRow++) {
            for (int secondRow = firstRow + 1;
                 secondRow < rows;
                 secondRow++) {
                for (int firstCol = 0;
                     firstCol < cols;
                     firstCol++) {
                    if (grid[firstRow][firstCol] == 0 ||
                        grid[secondRow][firstCol] == 0) {
                        continue;
                    }

                    for (int secondCol = firstCol + 1;
                         secondCol < cols;
                         secondCol++) {
                        if (grid[firstRow][secondCol] == 1 &&
                            grid[secondRow][secondCol] == 1) {
                            answer++;
                        }
                    }
                }
            }
        }

        return answer;
    }
};
