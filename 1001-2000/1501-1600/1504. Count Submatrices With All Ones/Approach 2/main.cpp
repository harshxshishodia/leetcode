class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows =
            static_cast<int>(mat.size());

        int cols =
            static_cast<int>(mat[0].size());

        int answer = 0;

        for (int top = 0; top < rows; top++) {
            vector<int> valid(
                cols,
                1
            );

            for (int bottom = top; bottom < rows; bottom++) {
                for (int col = 0; col < cols; col++) {
                    valid[col] &=
                        mat[bottom][col];
                }

                int consecutive = 0;

                for (int col = 0; col < cols; col++) {
                    if (valid[col]) {
                        consecutive++;
                        answer +=
                            consecutive;
                    } else {
                        consecutive = 0;
                    }
                }
            }
        }

        return answer;
    }
};
