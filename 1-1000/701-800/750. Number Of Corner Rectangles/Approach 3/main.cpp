class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int cols = static_cast<int>(grid[0].size());

        unordered_map<int, int> pairCount;
        int answer = 0;

        for (const vector<int>& row : grid) {
            vector<int> ones;

            for (int col = 0; col < cols; col++) {
                if (row[col] == 1) {
                    ones.push_back(col);
                }
            }

            for (int i = 0; i < static_cast<int>(ones.size()); i++) {
                for (int j = i + 1;
                     j < static_cast<int>(ones.size());
                     j++) {
                    int key =
                        ones[i] * cols +
                        ones[j];

                    answer += pairCount[key];
                    pairCount[key]++;
                }
            }
        }

        return answer;
    }
};
