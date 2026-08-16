class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int rows =
            static_cast<int>(grid.size());

        int cols =
            static_cast<int>(grid[0].size());

        vector<vector<bool>> fromStart(
            rows,
            vector<bool>(cols)
        );

        vector<vector<bool>> toEnd(
            rows,
            vector<bool>(cols)
        );

        if (grid[0][0] == 1) {
            fromStart[0][0] = true;
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) {
                    continue;
                }

                if (row > 0 &&
                    fromStart[row - 1][col]) {
                    fromStart[row][col] = true;
                }

                if (col > 0 &&
                    fromStart[row][col - 1]) {
                    fromStart[row][col] = true;
                }
            }
        }

        if (!fromStart[
                rows - 1
            ][
                cols - 1
            ]) {
            return true;
        }

        toEnd[
            rows - 1
        ][
            cols - 1
        ] = true;

        for (int row = rows - 1;
             row >= 0;
             row--) {
            for (int col = cols - 1;
                 col >= 0;
                 col--) {
                if (grid[row][col] == 0) {
                    continue;
                }

                if (row + 1 < rows &&
                    toEnd[row + 1][col]) {
                    toEnd[row][col] = true;
                }

                if (col + 1 < cols &&
                    toEnd[row][col + 1]) {
                    toEnd[row][col] = true;
                }
            }
        }

        int lastDiagonal =
            rows +
            cols -
            2;

        for (int diagonal = 1;
             diagonal < lastDiagonal;
             diagonal++) {
            int count = 0;

            for (int row = 0; row < rows; row++) {
                int col =
                    diagonal -
                    row;

                if (col < 0 ||
                    col >= cols) {
                    continue;
                }

                if (fromStart[row][col] &&
                    toEnd[row][col]) {
                    count++;
                }
            }

            if (count == 1) {
                return true;
            }
        }

        return false;
    }
};
