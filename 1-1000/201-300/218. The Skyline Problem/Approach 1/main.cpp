class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> coordinates;

        for (const vector<int>& building : buildings) {
            coordinates.push_back(building[0]);
            coordinates.push_back(building[1]);
        }

        sort(coordinates.begin(), coordinates.end());
        coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());

        vector<int> heights(coordinates.size() - 1, 0);

        for (const vector<int>& building : buildings) {
            int left = lower_bound(coordinates.begin(), coordinates.end(), building[0]) - coordinates.begin();
            int right = lower_bound(coordinates.begin(), coordinates.end(), building[1]) - coordinates.begin();

            for (int index = left; index < right; index++)
                heights[index] = max(heights[index], building[2]);
        }

        vector<vector<int>> answer;
        int previousHeight = 0;

        for (int index = 0; index < heights.size(); index++) {
            if (heights[index] != previousHeight) {
                answer.push_back({coordinates[index], heights[index]});
                previousHeight = heights[index];
            }
        }

        answer.push_back({coordinates.back(), 0});
        return answer;
    }
};