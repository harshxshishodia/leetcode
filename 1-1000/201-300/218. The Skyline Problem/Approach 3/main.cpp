class Solution {
    vector<vector<int>> mergeSkylines(const vector<vector<int>>& leftSkyline, const vector<vector<int>>& rightSkyline) {
        vector<vector<int>> merged;
        int leftIndex = 0;
        int rightIndex = 0;
        int leftHeight = 0;
        int rightHeight = 0;

        while (leftIndex < leftSkyline.size() || rightIndex < rightSkyline.size()) {
            int coordinate;

            if (rightIndex == rightSkyline.size() || (leftIndex < leftSkyline.size() && leftSkyline[leftIndex][0] < rightSkyline[rightIndex][0])) {
                coordinate = leftSkyline[leftIndex][0];
                leftHeight = leftSkyline[leftIndex][1];
                leftIndex++;
            } else if (leftIndex == leftSkyline.size() || rightSkyline[rightIndex][0] < leftSkyline[leftIndex][0]) {
                coordinate = rightSkyline[rightIndex][0];
                rightHeight = rightSkyline[rightIndex][1];
                rightIndex++;
            } else {
                coordinate = leftSkyline[leftIndex][0];
                leftHeight = leftSkyline[leftIndex][1];
                rightHeight = rightSkyline[rightIndex][1];
                leftIndex++;
                rightIndex++;
            }

            int currentHeight = max(leftHeight, rightHeight);

            if (merged.empty() || merged.back()[1] != currentHeight)
                merged.push_back({coordinate, currentHeight});
        }

        return merged;
    }

    vector<vector<int>> solve(const vector<vector<int>>& buildings, int left, int right) {
        if (left == right)
            return {{buildings[left][0], buildings[left][2]}, {buildings[left][1], 0}};

        int middle = left + (right - left) / 2;
        vector<vector<int>> leftSkyline = solve(buildings, left, middle);
        vector<vector<int>> rightSkyline = solve(buildings, middle + 1, right);
        return mergeSkylines(leftSkyline, rightSkyline);
    }

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return solve(buildings, 0, buildings.size() - 1);
    }
};