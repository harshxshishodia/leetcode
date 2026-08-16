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
                int common = 0;

                for (int col = 0; col < cols; col++) {
                    if (grid[firstRow][col] == 1 &&
                        grid[secondRow][col] == 1) {
                        common++;
                    }
                }

                answer +=
                    common *
                    (common - 1) /
                    2;
            }
        }

        return answer;
    }
};
