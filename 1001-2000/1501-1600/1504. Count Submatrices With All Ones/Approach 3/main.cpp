class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows =
            static_cast<int>(mat.size());

        int cols =
            static_cast<int>(mat[0].size());

        vector<vector<int>> width(
            rows,
            vector<int>(cols)
        );

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (mat[row][col] == 1) {
                    width[row][col] =
                        1 +
                        (
                            col > 0
                                ? width[row][col - 1]
                                : 0
                        );
                }
            }
        }

        int answer = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (width[row][col] == 0) {
                    continue;
                }

                int minimumWidth =
                    width[row][col];

                for (int top = row; top >= 0; top--) {
                    minimumWidth = min(
                        minimumWidth,
                        width[top][col]
                    );

                    if (minimumWidth == 0) {
                        break;
                    }

                    answer +=
                        minimumWidth;
                }
            }
        }

        return answer;
    }
};
