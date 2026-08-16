class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows =
            static_cast<int>(mat.size());

        int cols =
            static_cast<int>(mat[0].size());

        vector<int> height(cols);
        int answer = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (mat[row][col] == 0) {
                    height[col] = 0;
                } else {
                    height[col]++;
                }
            }

            vector<int> stack;
            vector<int> sum(cols);

            for (int col = 0; col < cols; col++) {
                while (!stack.empty() &&
                       height[stack.back()] >= height[col]) {
                    stack.pop_back();
                }

                if (stack.empty()) {
                    sum[col] =
                        height[col] *
                        (col + 1);
                } else {
                    int previous =
                        stack.back();

                    sum[col] =
                        sum[previous] +
                        height[col] *
                        (col - previous);
                }

                answer +=
                    sum[col];

                stack.push_back(col);
            }
        }

        return answer;
    }
};
