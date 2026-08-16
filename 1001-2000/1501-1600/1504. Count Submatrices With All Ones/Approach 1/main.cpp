class Solution {
    bool allOnes(
        const vector<vector<int>>& mat,
        int top,
        int left,
        int bottom,
        int right
    ) {
        for (int row = top; row <= bottom; row++) {
            for (int col = left; col <= right; col++) {
                if (mat[row][col] == 0) {
                    return false;
                }
            }
        }

        return true;
    }

public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows =
            static_cast<int>(mat.size());

        int cols =
            static_cast<int>(mat[0].size());

        int answer = 0;

        for (int top = 0; top < rows; top++) {
            for (int left = 0; left < cols; left++) {
                for (int bottom = top; bottom < rows; bottom++) {
                    for (int right = left; right < cols; right++) {
                        if (allOnes(
                                mat,
                                top,
                                left,
                                bottom,
                                right)) {
                            answer++;
                        }
                    }
                }
            }
        }

        return answer;
    }
};
