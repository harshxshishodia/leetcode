class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> heights(n, 0);
        vector<int> answer;
        int maximumHeight = 0;

        for (int index = 0; index < n; index++) {
            int left = positions[index][0];
            int right = left + positions[index][1];
            int baseHeight = 0;

            for (int previous = 0; previous < index; previous++) {
                int previousLeft = positions[previous][0];
                int previousRight = previousLeft + positions[previous][1];

                if (max(left, previousLeft) < min(right, previousRight))
                    baseHeight = max(baseHeight, heights[previous]);
            }

            heights[index] = baseHeight + positions[index][1];
            maximumHeight = max(maximumHeight, heights[index]);
            answer.push_back(maximumHeight);
        }

        return answer;
    }
};