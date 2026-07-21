class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> coordinates;

        for (const vector<int>& position : positions) {
            coordinates.push_back(position[0]);
            coordinates.push_back(position[0] + position[1]);
        }

        sort(coordinates.begin(), coordinates.end());
        coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());

        vector<int> heights(coordinates.size() - 1, 0);
        vector<int> answer;
        int maximumHeight = 0;

        for (const vector<int>& position : positions) {
            int left = lower_bound(coordinates.begin(), coordinates.end(), position[0]) - coordinates.begin();
            int right = lower_bound(coordinates.begin(), coordinates.end(), position[0] + position[1]) - coordinates.begin();
            int baseHeight = 0;

            for (int index = left; index < right; index++)
                baseHeight = max(baseHeight, heights[index]);

            int currentHeight = baseHeight + position[1];

            for (int index = left; index < right; index++)
                heights[index] = currentHeight;

            maximumHeight = max(maximumHeight, currentHeight);
            answer.push_back(maximumHeight);
        }

        return answer;
    }
};