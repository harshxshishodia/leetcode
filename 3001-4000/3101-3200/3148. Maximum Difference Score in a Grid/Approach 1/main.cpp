class Solution {
public:
    int maxScore(
        vector<vector<int>>& grid
    ) {
        int rows =
            static_cast<int>(
                grid.size()
            );

        int cols =
            static_cast<int>(
                grid[0].size()
            );

        int answer =
            numeric_limits<int>::min();

        for (int startRow = 0;
             startRow < rows;
             startRow++) {
            for (int startCol = 0;
                 startCol < cols;
                 startCol++) {
                for (int endRow = startRow;
                     endRow < rows;
                     endRow++) {
                    for (int endCol = startCol;
                         endCol < cols;
                         endCol++) {
                        if (
                            endRow == startRow &&
                            endCol == startCol
                        ) {
                            continue;
                        }

                        answer = max(
                            answer,
                            grid[endRow][endCol] -
                            grid[startRow][startCol]
                        );
                    }
                }
            }
        }

        return answer;
    }
};
